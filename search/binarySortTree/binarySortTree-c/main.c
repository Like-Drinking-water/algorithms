#include <stdio.h>
#include <stdlib.h>

/*****************************
********* ���������� *********
******************************/

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1

typedef int ElemType;
typedef int Status; 

//���������ݽṹ 
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

//���Ҷ����������е����� 
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

//���Ҳ�������� 
Status insertBST(BinaryTree *T, ElemType e) {
	BinaryTree P, tmp;
	//������������û�и����� 
	if (!searchBST(*T, e, NULL, &P)) {
		//�����ý�� 
		tmp = (BinaryTree)malloc(sizeof(BinaryNode));
		tmp->data = e;
		tmp->lchild = NULL;
		tmp->rchild = NULL;
		//�������ӵ������������� 
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
	//�������������Ѿ��и����� ����������� 
	else {
		return TRUE; 
	} 
}

//ɾ������ 
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
	//���û�������� 
	if (!(*T)->rchild) {
		q = *T;
		*T = (*T)->lchild;		
		free(q); 
	} 
	//���û�������� 
	else if (!(*T)->lchild){
		q = *T;
		*T = (*T)->rchild;		
		free(q); 
	}
	//��û��������Ҳû�������� 
	//����ǰ��(���) 
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
