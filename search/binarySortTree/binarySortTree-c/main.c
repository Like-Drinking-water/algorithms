#include <stdio.h>
#include <stdlib.h>

/*****************************
********* 二叉排序树 *********
******************************/

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1

typedef int ElemType;
typedef int Status; 

//二叉树数据结构 
typedef struct BinaryTree {
	ElemType data;
	struct BinaryTree *lchild, *rchild;
} BinaryNode, *BinaryTree;  


Status equal(int a, int b) {
	if (a == b) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

Status lt(int a, int b) {
	if (a < b) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

//查找二叉排序树中的数据 
BinaryTree searchBST(BinaryTree T, ElemType key, BinaryTree b, BinaryTree *P) {
	*P = b;
	if (!T) {
		return NULL;
	}
	if (equal(T->data, key)) {
		return T;
	}
	else if (lt(T->data, key)) {
		searchBST(T->rchild, key, T, P);
	} 
	else {
		searchBST(T->lchild, key, T, P); 
	}
}

//查找并添加数据 
Status insertBST(BinaryTree *T, ElemType e) {
	BinaryTree P, tmp;
	//二叉排序树中没有该数据 
	if (!searchBST(*T, e, NULL, &P)) {
		//创建好结点 
		tmp = (BinaryTree)malloc(sizeof(BinaryNode));
		tmp->data = e;
		tmp->lchild = NULL;
		tmp->rchild = NULL;
		//将结点添加到二叉排序树中 
		if (!P) {
			 *T = tmp;
		} 
		else {
			if (lt(P->data, e)) {
				P->rchild = tmp; 
			}
			else {
				P->lchild = tmp;
			}
		}
		return TRUE;	
	}
	//二叉排序树中已经有该数据 无需重新添加 
	else {
		return TRUE; 
	} 
}

//删除数据 
Status deleteBST(BinaryTree *T, ElemType key) {
	if (!*T) {
		return ERROR; 
	}
	if (equal((*T)->data, key)) {
		deleteT(T);
		return OK;
	}
	else if (lt((*T)->data, key)) {
		deleteBST(&(*T)->rchild, key);
	}
	else {
		deleteBST(&(*T)->lchild, key);
	}
}

Status deleteT(BinaryTree *T) {
	BinaryTree q, s; 
	//如果没有右子树 
	if (!(*T)->rchild) {
		q = *T;
		*T = (*T)->lchild;		
		free(q); 
	} 
	//如果没有左子树 
	else if (!(*T)->lchild){
		q = *T;
		*T = (*T)->rchild;		
		free(q); 
	}
	//既没有左子树也没有右子树 
	//查找前驱(后继) 
	else {
		s = (*T)->lchild;
		q = *T;
		while (s->rchild) {
			q = s;
			s = s->rchild;
		} 
		(*T)->data = s->data;
		if (q != *T) {
			q->rchild = s->lchild; 
		}
		else {
			q->lchild = s->lchild;
		}
		free(s);
	}
} 

int main(int argc, char *argv[]) {
	BinaryTree T, P;
	int i;
	int a[10] = {22, 33, 46, 77, 48, 89, 99, 20, 91, 25};
	T = NULL;
	for (i = 0; i < 10; i++) {
		insertBST(&T, a[i]);
	}
	P = searchBST(T, 33, NULL, &P);
	printf("%d\n", P->data);
	deleteBST(&T, 33);
	P = searchBST(T, 33, NULL, &P);
	printf("%d", P == NULL);
	return 0;
}
