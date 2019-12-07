#include <stdio.h>
#include <stdlib.h>

/***********************************
*********** ��ֵ���� ***************
************************************/
#define TRUE 1
#define FLASE 0

typedef int ElemType;

typedef struct {
	ElemType *data;
	int length;
}SSTable;

int equal(int a, int b) {
	if (a == b) {
		return TRUE;
	}
	else {
		return FLASE;
	}
}

int lt(int a, int b) {
	if (a < b) {
		return TRUE;
	}
	else {
		return FLASE;
	}
}

int interpolationSearch(SSTable *st, int key) {
	int low, high, mid;
	low = 0;
	high = st->length - 1;
	while (low <= high) {
		mid = low + (((key - st->data[low]) * (high - low + 1)) / (st->data[high] - st->data[low]));
		if (equal(st->data[mid], key)) {
			return mid;
		}
		//����ֵ���м�ֵ�� 
		else if (lt(st->data[mid], key)) {
			low = mid + 1;
		}
		//����ֵ���м�ֵС 
		else {
			high = mid - 1;
		}
	}
	return -1; 
} 

int main(int argc, char *argv[]) {
	SSTable *st;
	int i;
	st = (SSTable *)malloc(sizeof(SSTable));
	st->data = (ElemType *)malloc(sizeof(ElemType) * 10);
	st->length = 10;
	for (i = 0; i < 10; i++) {
		st->data[i] = 2 * i - 1;
	}
	printf("%d", interpolationSearch(st, 5));
	free(st->data);
	free(st);
	return 0;
}

