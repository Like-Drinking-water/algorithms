#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> 
 
/************************************
����ı�ʾ��ʵ�� 
*************************************/

#define MAX_ARRAY_DIM 8
#define OVERFLOW -2
#define UNDERFLOW -3
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct {
	//ά�� 
	int dim;
	//����ά��Ļ�ַ 
	int *bounds;
	//�����ӳ����������ַ 
	int *contants;
	//����������ݵĻ�ַ
	ElemType *base; 
} Array; 

//��ʼ������ 
Status initArray(Array *a, int dim, ...) {
	//��¼�����е�Ԫ������ 
	int elemTotal; 
	va_list ap;
	int i;
	elemTotal = 1; 
	if (dim < 1 || dim > MAX_ARRAY_DIM) {
		return ERROR;
	}
	a->dim = dim;
	a->bounds = (int *)malloc(dim * sizeof(int));
	if (!a->bounds) {
		//�����ڴ�ʧ�� 
		exit(OVERFLOW);
	}
	va_start(ap, dim);
	for (i = 0; i < dim; i++) {
		a->bounds[i] = va_arg(ap, int);
		if (a->bounds[i] < 0) {
			return UNDERFLOW;
		}
		elemTotal *= a->bounds[i];
	}
	va_end(ap);
	a->base = (ElemType *)malloc(elemTotal * sizeof(ElemType));
	if (!a->base) {
		//�ڴ����ʧ�� 
		exit(OVERFLOW); 
	}
	a->contants = (int *)malloc(dim * sizeof(int));
	if (!a->contants) {
		//�ڴ����ʧ��
		exit(OVERFLOW); 
	}
	a->contants[dim - 1] = 1;
	for (i = dim - 2; i >= 0; i--) {
		a->contants[i] = a->contants[i + 1] * a->bounds[i + 1];
	}
	return OK;
}

Status destroyArray(Array *a) {
	if (!a->base) {
		return ERROR;
	}
	free(a->base);
	a->base = NULL;
	if (!a->bounds) {
		return ERROR;
	}
	free(a->bounds);
	a->bounds = NULL;
	if (!a->contants) {
		return ERROR;
	}
	free(a->contants);
	a->contants = NULL;
	return OK; 
}

//����������±��������е����λ��
Status locate(Array a, int *off, va_list ap) {
	int i;
	int index;
	*off = 0;
	for (i = 0; i < a.dim; i++) {
		index = va_arg(ap, int);
		if (index < 0 || index >= a.bounds[i]) {
			return ERROR;
		}
		*off += index * a.contants[i];
	}
	return OK;
}

//��ȡ�±�Ԫ�ؽ��䱣�浽 e �� 
Status value(Array a, ElemType *e, ...) {
	va_list ap;
	int result;
	int off;
	va_start(ap, e);
	result = locate(a, &off, ap);
	if (result <= 0) {
		return result;
	} 
	*e = a.base[off];
	return OK;
} 

//�� e ��ֵ��������ָ���±� 
Status assign(Array *a, ElemType e, ...) {
	va_list ap;
	int result;
	int off;
	va_start(ap, e);
	result = locate(*a, &off, ap);
	if (result <= 0) {
		return ERROR;
	} 
	a->base[off] = e;
	return OK;
}

int main(void) {
	Array a;
	ElemType e;
	initArray(&a, 3, 4, 4, 4);
	assign(&a, 12, 2, 2, 2); 
	value(a, &e, 2, 2, 2);
	destroyArray(&a);
	printf("%d", e);
	return 0;
}
