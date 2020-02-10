#include <stdio.h>
#include <stdlib.h>

/* ≤Â»Î≈≈–Ú */
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

void insertSort(SqList *L) {
	int i, j;
	for (i = 2; i <= L->length; i++) {
		if (LT(L->r[i].key, L->r[i - 1].key)) {
			L->r[0] = L->r[i];
			L->r[i] = L->r[i - 1];
			for (j = i - 2; LT(L->r[0].key, L->r[j].key); j--) {
				L->r[j + 1] = L->r[j];
			}
			L->r[j + 1] = L->r[0];
		}	
	}
}

//’€∞Î≤Â»Î≈≈–Ú
void BInsertSort(SqList *L) {
	int i, j, low, high, m;
	for (i = 2; i <= L->length; i++) {
		L->r[0]= L->r[i];
		low = 1;
		high = i - 1;
		while (low <= high) {
			m = (low + high) / 2;
			if (LT(L->r[0].key, L->r[m].key)) {
				high = m - 1;
			}
			else {
				low = m + 1;
			}
		}
		for (j = i - 1; j >= high + 1; j--) {
			L->r[j + 1] = L->r[j];
		}
		L->r[high + 1] = L->r[0];
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
	BInsertSort(&L);
	for (i = 1; i <= L.length; i++) {
		printf("%d ", L.r[i]);
	}
	return 0;
}
