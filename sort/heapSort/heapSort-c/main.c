#include <stdio.h>
#include <stdlib.h>

/* ������(�Ӵ�С) */ 
#define MAX_SIZE 20

typedef int KeyType;
typedef int InfoType;

typedef struct {
	KeyType key;
	InfoType info;
} ReadType;

typedef struct {
	ReadType r[MAX_SIZE + 1];
	int length;
} SqList;

void initSqList(SqList *L) {
	L->length = 0;
}

int SqListInsert(SqList *L, KeyType key, InfoType info) {
	L->r[L->length + 1].key = key;
	L->r[L->length + 1].info = info;
	L->length++; 
}

void heapAdjust(SqList *L, int s, int m) {
	int i;
	ReadType rc;
	rc = L->r[s];
	//���½��бȽ� 
	for (i = s * 2; i <= m; i *= 2) {
		//�ҵ��ӽڵ��� key ��С�� 
		if (i < m && L->r[i].key > L->r[i + 1].key) {
			i++;
		}
		if (rc.key <= L->r[i].key) {
			break;
		}
		L->r[s] = L->r[i];
		s = i;
	}
	L->r[s] = rc;
} 

void swap(ReadType *a, ReadType *b) {
	ReadType c;
	c = *a;
	*a = *b;
	*b = c;
}

void heapSort(SqList *L) {
	int i;
	//���������Ա����ΪС����
	//���µ��Ͻ��е��� 
	for (i = L->length / 2; i > 0; i--) { 
		heapAdjust(L, i, L->length);
	}
	for (i = L->length; i > 1; i--) {
		swap(&(L->r[1]), &(L->r[i]));
		//����ΪС���� 
		heapAdjust(L, 1, i - 1);
	}
} 

int main(int argc, char *argv[]) {
	SqList L;
	int i;
	initSqList(&L);
	SqListInsert(&L, 11, 0);
	SqListInsert(&L, 21, 0);
	SqListInsert(&L, 31, 0);
	SqListInsert(&L, 44, 0);
	SqListInsert(&L, 22, 0);
	SqListInsert(&L, 33, 0);
	heapSort(&L);
	for (i = 1; i <= L.length; i++) {
		printf("%d ", L.r[i]);
	}
	return 0;
}
