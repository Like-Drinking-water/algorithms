#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> 
 
/************************************
数组的表示与实现 
*************************************/

#define MAX_ARRAY_DIM 8
#define OVERFLOW -2
#define UNDERFLOW -3
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct {
	//维数 
	int dim;
	//数组维界的基址 
	int *bounds;
	//数组的映像函数常数基址 
	int *contants;
	//存放数据数据的基址
	ElemType *base; 
} Array; 

//初始化数组 
Status initArray(Array *a, int dim, ...) {
	//记录数组中的元素总数 
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
		//分配内存失败 
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
		//内存分配失败 
		exit(OVERFLOW); 
	}
	a->contants = (int *)malloc(dim * sizeof(int));
	if (!a->contants) {
		//内存分配失败
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

//求出给出的下标在数组中的相对位置
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

//获取下标元素将其保存到 e 中 
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

//将 e 的值赋给数组指定下标 
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
