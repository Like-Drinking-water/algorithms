#include <stdio.h>
#include <stdlib.h>

/* 平衡二叉树 */
//左高 
#define LH 1 
//等高
#define EH 0
//右高
#define RH -1 
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct BSTNode {
	ElemType data;
	int BF;
	struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

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

//右旋 
void R_Rotate(BSTree *p) {
	BSTNode *lc;
	lc = (*p)->lchild;
	(*p)->lchild = lc->rchild;
	lc->rchild = *p;
	*p = lc;
}

//左旋 
void L_Rotate(BSTree *p) {
	BSTNode *rc;
	rc = (*p)->rchild;
	(*p)->rchild = rc->lchild;
	rc->lchild = *p;
	*p = rc;
}

//左高左平衡 
void LeftBalance(BSTree *T) {
	BSTNode *lc;
	BSTNode *rd;
	lc = (*T)->lchild;
	switch(lc->BF) {
		case LH:
			lc->BF = EH;
			(*T)->BF = EH;
			R_Rotate(T);
			break;
		case RH:
			rd = lc->rchild;
			switch(rd->BF) {
				case LH:
					lc->BF = EH;
					(*T)->BF = RH;
					break;
				case EH:
					lc->BF = EH;
					(*T)->BF = EH;
					break;
				case RH:
					lc->BF = LH;
					(*T)->BF = EH;
					break;
			}
			rd->BF = EH;
			L_Rotate(&((*T)->lchild));
			R_Rotate(T);
			break;
	}	
} 

//右高右平衡 
void RightBalance(BSTree *T) {
	BSTNode *rc;
	BSTNode *ld;
	rc = (*T)->rchild;
	switch(rc->BF) {
		case LH:
			ld = rc->lchild;
			switch(ld->BF) {
				case LH:
					rc->BF = RH;
					(*T)->BF = EH;
					break;
				case EH:
					rc->BF = EH;
					(*T)->BF = EH;
					break;
				case RH:
					rc->BF = EH;
					(*T)->BF = LH;
					break;
			}
			ld->BF = EH;
			R_Rotate(&((*T)->rchild));
			L_Rotate(T);
			break;
		case RH:
			rc->BF = EH;
			(*T)->BF = EH;
			L_Rotate(T);
			break;
	}	
} 

Status insertAVL(BSTree *T, ElemType e, int *taller) {
	//要添加的位置为空 创建空间 
	if (!(*T)) {
		*T = (BSTree)malloc(sizeof(BSTNode));
		(*T)->data = e;
		(*T)->BF = EH;
		(*T)->rchild = NULL;
		(*T)->lchild = NULL;
		*taller = 1;
	}
	else {
		//数据已存在无需添加 
		if (equal(e, (*T)->data)) {
			*taller = 0; 
			return 0;
		}
		//要添加的数据比当前指向的结点的数据小
		//添加到该结点的左子树 
		if (lt(e, (*T)->data)) {
			//添加失败 
			if (!insertAVL(&((*T)->lchild), e, taller)) {
				return 0; 
			} 
			if (taller) {
				switch ((*T)->BF) {
					case LH:
						LeftBalance(T);
						*taller = 0;
						break;
					case EH:
						(*T)->BF = LH;
						*taller = 1;
						break;
					case RH:
						(*T)->BF = EH;
						*taller = 0; 
						break;
				}
			}
		}
		//要添加的数据比当前指向的结点的数据大 
		//添加到该结点的右子树 
		else {
			//添加失败 
			if (!insertAVL(&((*T)->rchild), e, taller)) {
				return 0; 
			} 
			if (taller) {
				switch ((*T)->BF) {
					case LH:
						(*T)->BF = EH;
						*taller = 0;
						break;
					case EH:
						(*T)->BF = RH;
						*taller = 1;
						break;
					case RH:
						RightBalance(T);
						*taller = 0;
						break;
				}
			}
		}
	}
	return 1;
}


int main(int argc, char *argv[]) {
	BSTree T;
	int taller = 0;
	T = NULL;
	insertAVL(&T, 13, &taller);
	taller = 0;
	insertAVL(&T, 24, &taller);
	taller = 0;
	insertAVL(&T, 37, &taller);
	taller = 0;
	insertAVL(&T, 90, &taller);
	taller = 0;
	insertAVL(&T, 53, &taller);
	return 0;
}
