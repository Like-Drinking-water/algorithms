#include <stdio.h>
#include <stdlib.h>

/**********************************
Ѱ��ͼ�еĸ�� 
**********************************/
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
	int i;
	//��¼ʱ��� 
	count++;
	num[cur] = count;
	low[cur] = count;
	//���������ܹ�����ĵ� 
	for (i = 0; i < n; i++) {
		if (graph[cur][i] == 1) {
			//��ʾ��û�о��� 
			if (num[i] == 0) {
				//�����ӽڵ��������������� 
				dfs(i, cur); 
				//�����ܹ����������ʱ���
				low[cur] = min(low[i], low[cur]);
				//��ʾ���������ڵ�ز�������Ҳ�ز�������
				//˵�� cur - i �Ǹ�� 
				if (low[i] > num[cur]) {
					printf("%d - %d\n", cur, i);
				} 
			} 
			//����Լ������Ҳ��Ǹ��ڵ� ������ܹ����������ʱ��� 
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
	return 0;
}
