#include <stdio.h>
#include <stdlib.h>

/*******************************************************
问题：将两个有序递增线性表合成一个有序递增线性表 
********************************************************/
#define OVERFLOW -2
#define LIST_INIT_SIZE 20 //初始化线性储存空间的大小 
#define LISTINCREMENT 10 //线性表存储空间的增量 
 
typedef struct {
	int *elem;
	int length;
	int listsize;
} SqList; 

void initList(SqList *L) {
	L->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L->elem) {
		//内存空间分配失败 
		exit(OVERFLOW);
	}
	L->length = 0;
	L->listsize = 20; 
}

int listLength(SqList L) {
	return L.length;
}

void GetElem(SqList L, int i, int *e) {
	*e = L.elem[i];
}

void ListInsert(SqList *L, int i, int e) {
	int *p, *q; 
	//如果存储空间不足
	//重新分配内存空间 
	if (L->length == L->listsize) {
		L->elem = (int *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));
		if (!L->elem) {
			//分配空间失败 
			exit(OVERFLOW);
		}		
		L->listsize += LISTINCREMENT; 
	} 
	q = &(L->elem[i]);
	//将后面的元素向后移 
	for (p = &(L->elem[L->length - 1]); p >= q; p--) {
		*(p + 1) = *p;
	}
	*q = e;
	L->length++; 
}

void MergeList(SqList La, SqList Lb, SqList *Lc) {
	int i = 0, j = 0, k = 0;
	int a, b;
	int La_len, Lb_len;
	//初始化线性表Lc 
	initList(Lc);
	//获取两个线性表的长度 
	La_len = listLength(La);
	Lb_len = listLength(Lb);
	//将两个表合并 
	while ((i < La_len) && (j < Lb_len)) {
		//获取元素 
		GetElem(La, i, &a);
		GetElem(Lb, j, &b);
		if (a < b) {
			ListInsert(Lc, k, a);
			k++;
			i++;
		}
		else {
			ListInsert(Lc, k, b);
			k++;
			j++;
		}
	}
	//处理未添加完毕的线性表 
	while (i < La_len) {
		GetElem(La, i, &a);
		ListInsert(Lc, k, a);
		k++;
		i++;
	} 
	while (j < Lb_len) {
		GetElem(Lb, j, &b);
		ListInsert(Lc, k, b);
		k++;
		j++;
	}
}

int main(void) {
	int i, e;
	SqList La, Lb, Lc;
	initList(&La); 
	initList(&Lb); 
	for (i = 0; i < 4; i++) {
		scanf("%d", &e);
		ListInsert(&La, i, e);
	}
	for (i = 0; i < 7; i++) {
		scanf("%d", &e);
		ListInsert(&Lb, i, e);
	}
	MergeList(La, Lb, &Lc);
	for (i = 0; i < listLength(Lc); i++) {
		printf("%d ", Lc.elem[i]);
	}
	return 0;
}
