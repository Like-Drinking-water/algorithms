#include <stdio.h>
#include <stdlib.h>

/***********************************
*********** 折半查找 ***************
************************************/
#define TRUE 1
#define FALSE 0

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
		return FALSE;
	}
}

int lt(int a, int b) {
	if (a < b) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int halfIntervalSearch(SSTable *st, int key) {
	int low, high, mid;
	low = 0;
	high = st->length - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (equal(st->data[mid], key)) {
			return mid;
		}
		//查找值比中间值大 
		else if (lt(st->data[mid], key)) {
			low = mid + 1;
		}
		//查找值比中间值小 
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
	printf("%d", halfIntervalSearch(st, 6));
	return 0;
}
