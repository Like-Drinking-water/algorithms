#include <stdio.h>
#include <stdlib.h>

/*******************************************************
���⣺�ҵ����·�����ö�ά���鱣��ͼ�нڵ�Ĺ�ϵ��-1 ��ʾ�޷�
����;0 ��ʾ����Ϊ 0;������ʾ����õ�ľ��� 
�������������㷨 
********************************************************/
//���·���ĳ��� 
int min = 2147483647; 
//ͼ�Լ��߹��ı��
int **graph, *book; 
//ͼ�Ľڵ�����Լ�����
int n, m; 
//����·�� 
int *path, *shortestPath;
int top = 0, stop = 0;

void dfs(int start, int length) {
	int i;
	path[top] = start;
	top++;
	//��������յ��Ҿ����������̾������
	if (start == 4 && length < min) {
		//��ȡ��ǰ��̾��� 
		min = length;
		//�������·�� 
		for (i = 0; i < top; i++) {
			shortestPath[i] = path[i];
		}
		stop = top;
		return;
	}
	else {
		return;
	}
	for (i = 0; i < n; i++) {
		if (graph[start][i] > 0 && book[i] == 0) {
			book[i] = 1;
			dfs(i, length + graph[start][i]);
			book[i] = 0;
			top--;
		}
	}
	return;
} 

int main(void) {
	//���������Լ���ʱ�洢����
	int i, j, a, b, c;
	//����ڵ�������Լ����� 
	scanf("%d %d", &n, &m); 
	//��ͼ�����ռ� 
	graph = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++) {
		graph[i] = (int *)malloc(sizeof(int) * n);
	}
	//����Ǵ����ռ�
	book = (int *)malloc(sizeof(int) * n);
	//��ȡ�ڵ��ϵ
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			//������ͬ�ĵ�ľ���Ϊ0 
			if (i == j) {
				graph[i][j] = 0;
			}
			//�������ʼ��Ϊ -1 
			else {
				graph[i][j] = -1;
			}
		}
	}
	//��ȡ���Ե���ĵ� 
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
		graph[a][b] = c;
	} 
	//��ʼ�����
	for (i = 0; i < n; i++) {
		book[i] = 0;
	}
	//��ʼ��·��
	path = (int *)malloc(sizeof(int) * n);
	shortestPath = (int *)malloc(sizeof(int) * n);
	book[0] = 1;
	//�� 0 ��ʼѰ�����·�� 
	dfs(0, 0); 
	//��ӡ���·���Լ����� 
	for (i = 0; i < stop - 1; i++) {
		printf("%d -> ", shortestPath[i]);
	} 
	printf("4    length = %d", min);
	return 0;
}
