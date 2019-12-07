#include <stdio.h>
#include <stdlib.h>

/***********************************
******** 쳲��������� **************
************************************/

#define TRUE 1
#define FLASE 0
//쳲���������ĳ��� 
#define MAX_SIZE 20
#define ERROR -1

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

void fibonacci(int *f) {
	int i;
	f[0] = 0;
	f[1] = 1;
	for (i = 2; i < MAX_SIZE; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
}

int fibonacciSearch(SSTable *st, int key) {
	int *f;
	int k = 0, i;
	int low, mid, high;
	int *tmp;
	f = (int *)malloc(sizeof(int) * MAX_SIZE);
	//���쳲��������� 
	fibonacci(f);
	while (f[k] - 1 < st->length) {
		k++;
		//���鳤�ȴ���쳲�������������ֵ 
		if (k == 20) {
			return ERROR;
		}
	}
	//��ԭ������������� 
	tmp = (int *)malloc(sizeof(int) * (f[k] - 1));
	for (i = 0; i < st->length; i++) {
		tmp[i] = st->data[i];
	}
	for (i = st->length; i < f[k] - 1; i++) {
		tmp[i] = st->data[st->length - 1];
	}
	low = 0;
	high = f[k - 1] - 2;
	while (low <= high) {
		mid = low + f[k - 1] - 1;
		if (equal(tmp[mid], key)) {
			if (mid >= st->length) {
				return  st->length - 1;
			}
			return mid;
		}
		//����ֵ���м�ֵ�� 
		else if (lt(tmp[mid], key)) {
			low = mid + 1;
			k -= 2;
		}
		//����ֵ���м�ֵС 
		else {
			high = mid - 1;
			k -= 1;
		}
	}
	free(tmp);
	return -2;
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
	printf("%d", fibonacciSearch(st, 5));
	free(st->data);
	free(st);
	return 0;
}
