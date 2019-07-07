#include <stdio.h>
#include <stdlib.h>

/*******************************************************
���⣺����������������Ա�ϳ�һ������������Ա� 
********************************************************/
#define OVERFLOW -2
#define LIST_INIT_SIZE 20 //��ʼ�����Դ���ռ�Ĵ�С 
#define LISTINCREMENT 10 //���Ա�洢�ռ������ 
 
typedef struct {
	int *elem;
	int length;
	int listsize;
} SqList; 

void initList(SqList *L) {
	L->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L->elem) {
		//�ڴ�ռ����ʧ�� 
		exit(OVERFLOW);
	}
	L->length = 0;
	L->listsize = 20; 
}

int listLength(SqList L) {
	return L.length;
}

void GetElem(SqList L, int i, int *e) {
	*e = L.elem[i];
}

void ListInsert(SqList *L, int i, int e) {
	int *p, *q; 
	//����洢�ռ䲻��
	//���·����ڴ�ռ� 
	if (L->length == L->listsize) {
		L->elem = (int *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));
		if (!L->elem) {
			//����ռ�ʧ�� 
			exit(OVERFLOW);
		}		
		L->listsize += LISTINCREMENT; 
	} 
	q = &(L->elem[i]);
	//�������Ԫ������� 
	for (p = &(L->elem[L->length - 1]); p >= q; p--) {
		*(p + 1) = *p;
	}
	*q = e;
	L->length++; 
}

void MergeList(SqList La, SqList Lb, SqList *Lc) {
	int i = 0, j = 0, k = 0;
	int a, b;
	int La_len, Lb_len;
	//��ʼ�����Ա�Lc 
	initList(Lc);
	//��ȡ�������Ա�ĳ��� 
	La_len = listLength(La);
	Lb_len = listLength(Lb);
	//��������ϲ� 
	while ((i < La_len) && (j < Lb_len)) {
		//��ȡԪ�� 
		GetElem(La, i, &a);
		GetElem(Lb, j, &b);
		if (a < b) {
			ListInsert(Lc, k, a);
			k++;
			i++;
		}
		else {
			ListInsert(Lc, k, b);
			k++;
			j++;
		}
	}
	//����δ�����ϵ����Ա� 
	while (i < La_len) {
		GetElem(La, i, &a);
		ListInsert(Lc, k, a);
		k++;
		i++;
	} 
	while (j < Lb_len) {
		GetElem(Lb, j, &b);
		ListInsert(Lc, k, b);
		k++;
		j++;
	}
}

int main(void) {
	int i, e;
	SqList La, Lb, Lc;
	initList(&La); 
	initList(&Lb); 
	for (i = 0; i < 4; i++) {
		scanf("%d", &e);
		ListInsert(&La, i, e);
	}
	for (i = 0; i < 7; i++) {
		scanf("%d", &e);
		ListInsert(&Lb, i, e);
	}
	MergeList(La, Lb, &Lc);
	for (i = 0; i < listLength(Lc); i++) {
		printf("%d ", Lc.elem[i]);
	}
	return 0;
}
