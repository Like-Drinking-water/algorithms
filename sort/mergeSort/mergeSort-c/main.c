#include <stdio.h>
#include <stdlib.h>

/* 归并排序 */
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

//将 rt1[s...m] 和 rt1[m + 1...t] 合并到 rt2 
void merge(ReadType rt1[], ReadType rt2[], int s, int m, int t) {
	int i, j, k;
	for (i = s, j = m + 1, k = s; i <= m && j <= t; k++) {
		if (rt1[i].key <= rt1[j].key) {
			rt2[k] = rt1[i];
			i++;
		}
		else {
			rt2[k] = rt1[j];
			j++;
		}
	} 
	if (i <= m) {
		for (;i <= m; i++, k++) {
			rt2[k] = rt1[i];
		}
	}
	if (j <= t) {
		for (;j <= t; j++, k++) {
			rt2[k] = rt1[j];
		}
	}
}

void mSort(ReadType rt1[], ReadType rt2[], int s, int t) {
	ReadType rt3[MAX_SIZE + 1];
	int m;
	if (s == t) {
		rt2[s] = rt1[s];
	}
	else {
		m = (s + t) / 2;
		mSort(rt1, rt3, s, m);
		mSort(rt1, rt3, m + 1, t);
		merge(rt3, rt2, s, m, t);
	}
}
 
void mergeSort(SqList *L) {
	ReadType rt1[MAX_SIZE + 1];
	int i;
	for (i = 1; i <= L->length; i++) {
		rt1[i] = L->r[i];
	}
	mSort(rt1, L->r, 1, L->length);
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
	mergeSort(&L);
	for (i = 1; i <= L.length; i++) {
		printf("%d ", L.r[i].key);
	}
	return 0;
}
