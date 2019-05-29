#include <stdio.h>
#include <stdlib.h>

/***************************************************
���⣺��Դ���·�� 
�����ʹ�� Dijkstra �㷨 
***************************************************/

int main(void) {
	//ͼ 
	int **graph;
	int *dis;
	int min;
	//·��
	int **path;
	int last = 0;
	//��� int ֵ ��Ϊ������ֵ 
	int inf = 214783647;
	//����Ƿ���֪���·��
	int *book;
	//�ڵ����ͱ���
	int n, m;
	//������������ʱ�洢����
	int i, j, u, v, a, b, c;
	//��Դ���·������� 
	int s;
	//��ȡ�ڵ�������Լ������������ 
	scanf("%d %d %d", &n, &m, &s); 
	//��ͼ�����ռ� 
	graph = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++) {
		graph[i] = (int *)malloc(sizeof(int) * n);
	}
	//��·������ռ� 
	path = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++) {
		path[i] = (int *)malloc(sizeof(int) * n);
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
	//��ʼ����־
	book = (int *)malloc(sizeof(int) * n);
	//��ʼ��Դ�����
	dis = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		dis[i] = graph[s][i];
	} 
	//��ǳ�ʼ��
	for (i = 0; i < n; i++) {
		book[i] = 0;
	} 
	//Դ�㵽Դ���Ѿ��������·�� 
	book[s] = 1;
	//��ʼ��·�� 
	for (i = 0; i < n; i++) {
		path[i][0] = s;
	}
	last++;
	//Dijstra �㷨���Ĵ��� 
	for (i = 0; i < n - 1; i++) {
		min = inf;
		//�ҵ���Դ������ĵ� 
		for (j = 0; j < n; j++) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		} 
		book[u] = 1;
		if (last == 1) {
			path[u][last] = u;
		}
		last++;
		for (v = 0; v < n; v++) {
			//��ʾ�ܹ����� 
			if (graph[u][v] < inf) {
				if (book[v] == 0 && dis[v] > min + graph[u][v]) {
					dis[v] = min + graph[u][v];
					//�ϳ�·�� 
					for (j = 0; j < last; j++) {
						path[v][j] = path[u][j];
					}
					path[v][last] = v;
				} 	
			}
		}
	}
	//������
	for (i = 0; i < n; i++) {
		printf("%d ", dis[i]);
	} 
	printf("\n");
	//���·��
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == path[i][j]) {
				printf("%d\n", i);
				break;
			} 
			printf("%d -> ", path[i][j]);
		} 
	} 
	return 0;
}
