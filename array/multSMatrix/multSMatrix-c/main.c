#include <stdio.h>
#include <stdlib.h>

/*****************************
矩阵相乘 
******************************/ 

#define ERROR 0
#define OK 1
#define MAXSIZE 100
#define MAXRC 100

typedef int Status;
typedef int ElemType;

typedef struct {
	//行 列 
	int i, j;
	ElemType e; 
} Triple;

typedef struct {
	//非零元 
	Triple data[MAXSIZE + 1];
	//记录矩阵的行数列数以及非零元的总数 
	int mu, nu, tu;
	int rpos[MAXRC + 1]; 
} SMatrix;

//初始化稀疏矩阵 
Status initSMatrix(SMatrix *s, int mu, int nu, int tu, Triple data[]) {
	int n, m;
	int num[MAXRC + 1];
	Triple tmp;
	s->mu = mu;
	s->nu = nu;
	s->tu = tu;
	for (n = 1; n <= mu; n++) {
		num[n] = 0;
	}
	for (n = 1; n <= tu; n++) {
		if (data[n].i <= 0 || data[n].i > mu || data[n].j <= 0 || data[n].j > nu) {
			return ERROR;
		}
		//记录每一行非零元的个数 
		num[data[n].i]++;
	}
	for (n = 1; n <= tu; n++) {
		for (m = 1; m <= tu - n; m++) {
			if (data[m].i > data[m + 1].i) {
				tmp = data[m];
				data[m] = data[m + 1];
				data[m + 1] = tmp;
			}
			else if (data[m].i == data[m + 1].i && data[m].j > data[m + 1].j) {
				tmp = data[m];
				data[m] = data[m + 1];
				data[m + 1] = tmp;
			}
		}
	}
	for (n = 1; n <= tu; n++) {
		s->data[n] = data[n];
	}
	s->rpos[1] = 1;
	for (n = 2; n <= mu; n++) {
		s->rpos[n] = s->rpos[n - 1] + num[n - 1];
	}
	return OK;
}

// M ×N = Q
// 矩阵相乘 
Status multSMatrix(SMatrix *M, SMatrix *N, SMatrix *Q) {
	int row, col, p, q, top, t;
	ElemType temp[MAXRC + 1];
	//不满足矩阵相乘的条件 
	if (M->nu != N->mu) {
		return ERROR;
	}
	Q->mu = M->mu;
	Q->nu = N->nu;
	Q->tu = 0;
	if (M->tu * N->tu != 0) {
		for (row = 1; row <= M->mu; row++) {
			for (p = 1; p <= N->nu; p++) {
				temp[p] = 0;
			}
			Q->rpos[row] = Q->tu + 1;
			//获取当前行在 data 最后位置 
			if (row < M->mu) {
				top = M->rpos[row + 1];
			}
			else {
				top = M->tu + 1;
			}
			for (q = M->rpos[row]; q < top; q++) {
				//找到相乘矩阵的行数 
				col = M->data[q].j;
				//获取当前行在 data 最后位置 
				if (col < N->mu) {
					t = N->rpos[col + 1];
				}
				else {
					t = N->tu + 1;
				}
				//进行相乘后保存在 temp 中 
				for (p = N->rpos[col]; p < t; p++) {
					temp[N->data[p].j] += N->data[p].e * M->data[q].e;
				}
			}
			for (p = 1; p <= N->nu; p++) {
				if (temp[p]) {
					Q->tu++;
					if (Q->tu > MAXSIZE) {
						return ERROR;
					}
					Q->data[Q->tu].i = row;
					Q->data[Q->tu].j = p;
					Q->data[Q->tu].e = temp[p]; 
				}
			} 
		}
	}
}

int main(void) {
	int i;
	SMatrix M, N, Q;
	Triple data[MAXSIZE + 1];
	data[1].i = 2; data[1].j = 2; data[1].e = -1;
	data[2].i = 1; data[2].j = 4; data[2].e = 5;
	data[3].i = 1; data[3].j = 1; data[3].e = 3;
	data[4].i = 3; data[4].j = 1; data[4].e = 2;
	initSMatrix(&M, 3, 4, 4, data);
	
	data[1].i = 3; data[1].j = 1; data[1].e = -2;
	data[2].i = 2; data[2].j = 1; data[2].e = 1;
	data[3].i = 1; data[3].j = 2; data[3].e = 2;
	data[4].i = 3; data[4].j = 2; data[4].e = 4;
	initSMatrix(&N, 4, 2, 4, data);
	
	multSMatrix(&M, &N, &Q);
	for (i = 1; i <= Q.tu; i++) {
		printf("%d %d %d\n", Q.data[i].i, Q.data[i].j, Q.data[i].e);
	}
	return 0;
}
