#include <stdio.h>
#include <stdlib.h>

/* ƽ������� */
//��� 
#define LH 1 
//�ȸ�
#define EH 0
//�Ҹ�
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

//���� 
void R_Rotate(BSTree *p) {
	BSTNode *lc;
	lc = (*p)->lchild;
	(*p)->lchild = lc->rchild;
	lc->rchild = *p;
	*p = lc;
}

//���� 
void L_Rotate(BSTree *p) {
	BSTNode *rc;
	rc = (*p)->rchild;
	(*p)->rchild = rc->lchild;
	rc->lchild = *p;
	*p = rc;
}

//�����ƽ�� 
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

//�Ҹ���ƽ�� 
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
	//Ҫ��ӵ�λ��Ϊ�� �����ռ� 
	if (!(*T)) {
		*T = (BSTree)malloc(sizeof(BSTNode));
		(*T)->data = e;
		(*T)->BF = EH;
		(*T)->rchild = NULL;
		(*T)->lchild = NULL;
		*taller = 1;
	}
	else {
		//�����Ѵ���������� 
		if (equal(e, (*T)->data)) {
			*taller = 0; 
			return 0;
		}
		//Ҫ��ӵ����ݱȵ�ǰָ��Ľ�������С
		//��ӵ��ý��������� 
		if (lt(e, (*T)->data)) {
			//���ʧ�� 
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
		//Ҫ��ӵ����ݱȵ�ǰָ��Ľ������ݴ� 
		//��ӵ��ý��������� 
		else {
			//���ʧ�� 
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
