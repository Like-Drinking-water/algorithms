#include <stdio.h>
#include <stdlib.h>

/***************************************************
���⣺�ҵ�ͼ�����ڵ�����·��
�����ʹ�� Floyd-Warshall �㷨 
***************************************************/

int main() {
	//��� int ֵ ��Ϊ������ֵ 
	int inf = 214783647;
	//ͼ�нڵ�������Լ�����
	int n, m;
	//���������Լ���ʱ�洢����
	int i, j, k, a, b, c; 
	//ͼ 
	int **graph;
	//��ȡ�ڵ�������Լ�����
	scanf("%d %d", &n, &m); 
	//��ͼ�����ռ� 
	graph = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++) {
		graph[i] = (int *)malloc(sizeof(int) * n);
	}
	//��ȡ�ڵ��ϵ
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			//������ͬ�ĵ�ľ���Ϊ0 
			if (i == j) {
				graph[i][j] = 0;
			}
			//�������ʼ��Ϊ -1 
			else {
				graph[i][j] = inf;
			}
		}
	}
	//��ȡ���Ե���ĵ� 
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
	}
	// Floyd-Warshall �㷨�������
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (graph[i][k] < inf && graph[k][j] < inf && graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	} 
	//��ӡ���
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%2d", graph[i][j]);
		}
		printf("\n");
	} 
	return 0;
}
