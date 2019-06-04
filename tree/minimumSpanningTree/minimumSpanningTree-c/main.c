#include <stdio.h>
#include <stdlib.h>

/*****************************
��С���������� 
******************************/ 
//��ʾ�����ڵ��Լ�֮���Ȩֵ 
typedef struct {
	int u;
	int v;
	int w;
} Edge; 

int f[10];

void quickSort(Edge *edge, int left, int right) {
	int i, j;
	Edge tmp;
	//��ʾ���� 
	if (left >= right) {
		return;
	}
	i = left;
	j = right;
	while (i != j) {
		//����߿�ʼѰ�ұȻ�ֵ����� 
		while (edge[i].w <= edge[left].w && i < j) {
			i++;
		}
		//���ұ߿�ʼѰ�ұȻ�ֵС����
		while (edge[j].w >= edge[left].w && i < j) {
			j--;
		} 
		//��ʾ������û������ 
		if (i < j) {
			tmp = edge[i];
			edge[i] = edge[j];
			edge[j] = tmp; 
		}
	} 
	//������ֵ��λ��
	tmp = edge[left];
	edge[left] = edge[i];
	edge[i] = tmp; 
	//���еݹ�
	quickSort(edge, left, i - 1);
	quickSort(edge, i + 1, right);
	return; 
} 

//��ȡ���ڵ� 
int getFather(int v) {
	if (f[v] == v) {
		return v;
	}
	else {
		f[v] = getFather(f[v]);
		return f[v];
	}
}

//�ϲ��������ϵĹ�ϵ 
int merge(int u, int v) {
	int t1, t2;
	t1 = getFather(u);
	t2 = getFather(v);
	if (t1 != t2) {
		f[t2] = t1;
		return 1;
	}
	return 0;
} 

int main(void) {
	int i;
	Edge edge[20];
	int count = 0, sum = 0; 
	//�ڵ����Լ����� 
	int n, m;
	//��ȡ�ڵ��������
	scanf("%d %d", &n, &m);
	//��ȡ�ߵ�Ȩֵ
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
	}
	//��Ȩֵ���д�С�������� 
	quickSort(edge, 0, m - 1);
	//���鼯��ʼ��
	for (i = 0; i < n; i++) {
		f[i] = i;
	} 
	//Kruskal �㷨���Ĳ��� 
	for (i = 0; i < m; i++) {
		//��һ����ͨ 
		if (merge(edge[i].u, edge[i].v)) {
			count++;
			sum += edge[i].w;
		}
		//��С��������Ҫ�� n - 1 ���� 
		if (count == n - 1) {
			break;
		}
	}
	printf("%d", sum); 
	return 0;
}
