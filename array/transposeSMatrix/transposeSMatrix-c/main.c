#include <stdio.h>
#include <stdlib.h>

/*************************************
稀疏矩阵的转置 
**************************************/ 
//非零元个数的最大值 
#define MAXSIZE 1000

typedef int ElemType;

typedef struct {
	int i, j;
	ElemType e;
} Triple; 

typedef struct {
	Triple data[MAXSIZE + 1];
	//行数 列数 非零元总数 
	int mu, nu, tu;
} TSMatrix;

//void transposeSMatrix(TSMatrix *m, TSMatrix *t) {
//	int col, p, q;
//	t->mu = m->nu;
//	t->nu = m->mu;
//	t->tu = m->tu;
//	if (t->tu) {
//		q = 1;
//		for (col = 1; col <= m->nu; col++) {
//			for (p = 1; p <= m->tu; p++) {
//				if (m->data[p].j == col) {
//					t->data[q].i = m->data[p].j;
//					t->data[q].j = m->data[p].i;
//					t->data[q].e = m->data[p].e;
//					q++;
//				}
//			}
//		}
//	} 
//}

//优化 
void transposeSMatrix(TSMatrix *m, TSMatrix *t) {
	int col, p, q;
	//某一列中非零元的个数
	//某一列第一个非零元在 t.data 的位置 
	int *num, *cpot; 
	t->mu = m->nu;
	t->nu = m->mu;
	t->tu = m->tu;
	if (t->tu) {
		num = (int *)malloc((m->nu + 1) * sizeof(int));
		cpot = (int *)malloc((m->nu + 1) * sizeof(int));
		//初始化 num 
		for (col = 1; col <= m->nu; col++) {
			num[col] = 0;
		}
		//获取 num
		for (p = 1; p <= m->tu; p++) {
			num[m->data[p].j]++;
		} 
		//获取 cpot 
		cpot[1] = 1;
		for (col = 2; col <= m->nu; col++) {
			cpot[col] = cpot[col - 1] + num[col - 1];
		}
		for (p = 1; p <= m->tu; p++) {
			col = m->data[p].j;
			q = cpot[col];
			t->data[q].i = m->data[p].j;
			t->data[q].j = m->data[p].i;
			t->data[q].e = m->data[p].e;
			cpot[col]++; 
		} 
	} 
}

void printSMatrix(TSMatrix *m) {
	int p, q, n;
	n = 1;
	for (p = 1; p <= m->mu; p++) {
		for (q = 1; q <= m->nu; q++) {
			if (m->data[n].i == p && m->data[n].j == q) {
				printf("%2d", m->data[n].e);
				n++; 
			}
			else {
				printf("%2d", 0);
			}
		}
		printf("\n");
	}
}

int main(void) {
	TSMatrix m, t;
	m.mu = 4;
	m.nu = 4;
	m.tu = 4;
	m.data[1].i = 1;
	m.data[1].j = 3;
	m.data[1].e = 8;
	m.data[2].i = 2;
	m.data[2].j = 1;
	m.data[2].e = 4;
	m.data[3].i = 2;
	m.data[3].j = 3;
	m.data[3].e = 5;
	m.data[4].i = 4;
	m.data[4].j = 4;
	m.data[4].e = 2;
	transposeSMatrix(&m, &t);
	printSMatrix(&m);
	printf("----------------------------\n");
	printSMatrix(&t);
	return 0;
}
