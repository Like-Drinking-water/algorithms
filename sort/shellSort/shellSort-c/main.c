#include <stdio.h>
#include <stdlib.h>

/* Ï£¶ûÅÅÐò */
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

int  LT(int a, int b) {
	if (a < b) {
		return 1;
	}
	else {
		return 0;
	}
}

void initSqList(SqList *L) {
	L->length = 0;
}

int SqListInsert(SqList *L, KeyType key, InfoType info) {
	L->r[L->length + 1].key = key;
	L->r[L->length + 1].info = info;
	L->length++; 
}

void shellSort(SqList *L) {
	int dt;
	int i, j;
	dt = L->length;
	do {
		dt = dt / 3 + 1;
		for (i = dt + 1; i <= L->length; i++) {
			if (LT(L->r[i].key, L->r[i - dt].key)) {
				L->r[0] = L->r[i];
				for (j = i - dt; LT(L->r[0].key, L->r[j].key); j -= dt) {
					L->r[j + dt] = L->r[j];
				}
				L->r[j + dt] = L->r[0]; 
			}
		}
	} while (dt != 1);
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
	shellSort(&L);
	for (i = 1; i <= L.length; i++) {
		printf("%d ", L.r[i]);
	}
	return 0;
}
