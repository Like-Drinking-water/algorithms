#include <stdio.h>
#include <stdlib.h>

/***********************************
*********** 折半查找 ***************
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

int halfIntervalSearch(SSTable *st, int key) {
	int low, high, min;
	low = 0;
	high = st->length - 1;
	while (low <= high) {
		min = (low + high) / 2;
		if (equal(st->data[min], key)) {
			return min;
		}
		//查找值比中间值大 
		else if (lt(st->data[min], key)) {
			low = min + 1;
		}
		//查找值比中间值小 
		else {
			high = min - 1;
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
	printf("%d", halfIntervalSearch(st, 6));
	return 0;
}
