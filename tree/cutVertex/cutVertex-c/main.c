#include <stdio.h>
#include <stdlib.h>

/********************************************
���⣺Ѱ�Ҹ�� 
*********************************************/ 
int root;
//��ʾĳ�����ܹ�����������ʱ����Լ�����ö����ʱ��� 
int low[20], num[20];
//ͼ 
int graph[20][20];
//������¼ʱ��� 
int count;
//ͼ�еĶ������Լ����� 
int n, m;
//����Ƿ��Ǹ�� 
int flag[20];

//��Сֵ 
int min(int x, int y) {
	return x > y ? y : x; 
}

void dfs(int cur, int father) {
	//������¼���ӵ����� 
	int child = 0, i;
	//��¼����ʱ���ʱ��� 
	count++; 
	num[cur] = count;
	low[cur] = count;
	//�����ܹ��ﵽ�ĵ� 
	for (i = 0; i < n; i++) {
		if (graph[cur][i] == 1) {
			//��ʾ��û��������� 
			if (num[i] == 0) {
				dfs(i, cur);
				child++;
				//���µ�ǰ�����ܹ����������ʱ��� 
				low[cur] = min(low[cur], low[i]);
				//��� cur ���Ǹ���� �� i �ܹ����������ʱ������� cur ��ʱ���
				//����� cur �Ǹ��
				if (cur != root && low[i] >= num[cur]) {
					flag[cur] = 1; 
				}
				//����Ǹ���� ����Ҫ�������������ϵĺ��Ӳ��Ǹ��
				if (cur == root && child >= 2) {
					flag[cur] = 1;	
				} 
			} 
			//������������ ������㲻�ǵ�ǰ���� 
			else if (i != father) {
				low[cur] = min(low[cur], num[i]);
			}
		}
	} 
} 

int main(void) {
	int i, j, x, y;
	//��ȡ�������Լ����� 
	scanf("%d %d", &n, &m);
	//��ʼ��ͼ
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			graph[i][j] = 0;
		} 
	} 
	//��ȡͼ
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	} 
	root = 0;
	//�� 0 �Ŷ��㿪ʼ�������
	dfs(0, root);
	for (i = 0; i < n; i++) {
		if (flag[i] == 1) {
			printf("%d ", i);
		}
	} 
	return 0;
}
