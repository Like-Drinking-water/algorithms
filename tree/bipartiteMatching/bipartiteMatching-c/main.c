#include <stdio.h>
#include <stdlib.h>

/********************************************
���⣺����ͼƥ�� 
********************************************/
//��¼��� 
int match[20];
//ͼ 
int graph[20][20];
//�����Լ��������
int n, m; 
//����Ƿ��Ѿ�����
int book[20];

int dfs(int u) {
	int i;
	for (i = 0; i < n; i++) {
		if (book[i] == 0 && graph[u][i] == 1) {
			//����Ѿ����� 
			book[i] = 1;
			if (match[i] == -1 || dfs(match[i]) == 1) {
				//������Թ�ϵ
				match[i] = u;
				match[u] = i;
				return 1; 
			} 
		}
	}
	return 0;
} 

int main(void) {
	int i, j;
	int x, y;
	//��¼������� 
	int sum = 0; 
	//��ȡͼ�Ĵ�С
	scanf("%d %d", &n, &m);
	//��ȡͼ
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	} 
	
	for (i = 0; i < n; i++) {
		match[i] = -1;
	}
	for (i = 0; i < n; i++) {
		//��ձ�� 
		for (j = 0; j < n; j++) {
			book[j] = 0;
		}
		if (dfs(i)) {
			sum++;
		} 
	}
	printf("%d", sum);
	return 0;
}
