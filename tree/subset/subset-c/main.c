#include <stdio.h>
#include <stdlib.h>

/* 求子集 */

typedef struct {
	int *data;
	int length;
	int size;
}List;

int ListLength(List l) {
	return l.length;
}

void Output(List l) {
	int i;
	if (l.length == 0) {
		printf("空集"); 
	}
	else {
		for (i = 0; i < l.length; i++) {
			printf("%d", l.data[i]);
		} 
	}
	printf(" ");
} 

void GetElem(List l, int index, int *result) {
	*result = l.data[index];
}

void ListInsert(List *l, int index, int d) {
	l->data[index] = d;
	l->length++;
} 

void ListDeleteLast(List *l) {
	l->length--; 
}

void GetPowerSet(int i, List A, List *B) {
	int x;
	int k;
	if (i > ListLength(A) - 1) {
		Output(*B);
	}
	else {
		GetElem(A, i, &x);
		k = ListLength(*B);
		ListInsert(B, k, x);
		GetPowerSet(i + 1, A, B);
		ListDeleteLast(B);
		GetPowerSet(i + 1, A, B);
	}
}

int main(int argc, char *argv[]) {
	List A, B;
	A.data = (int *)malloc(sizeof(int) * 10);
	A.data[0] = 1;
	A.data[1] = 2;
	A.data[2] = 3;
	A.length = 3;
	B.data = (int *)malloc(sizeof(int) * 10);
	B.length = 0;
	GetPowerSet(0, A, &B);
	return 0;
}
