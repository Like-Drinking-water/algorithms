#include <stdio.h>
#include <stdlib.h>

/*******************************************************
���⣺ͼ�ı������ö�ά���鱣��ͼ�нڵ�Ĺ�ϵ��-1 ��ʾ�޷�
����;0 ��ʾ����Ϊ 0;1 ��ʾ���Ե���
�������������㷨 
********************************************************/
//�ڵ�������Լ����� 
int n, m; 
/**
* ��������㷨
* @Param start ��ʼ�����Ľڵ�
* @Param graph ����ڵ��ϵ������
* @Param book ��־·���Ƿ��߹� 
*/
void dfs(int start, int **graph, int *book) {
	int j;
	printf("���� %d �Žڵ�\n", start);
	book[start] = 1; 
	//���Խ��������� 
	for (j = 0; j < n; j++) {
		//�ܹ����ﲢ�һ�δȥ�� 
		if (graph[start][j] == 1 && !book[j]) {
			dfs(j, graph, book); 
		}
	}
	return; 
} 

int main(int argc, char *argv[]) {
	//��ʱ�洢
	int a, b; 
	//��������
	int i, j; 
	//����ڵ��ϵ�Լ��߹��ı�־ 
	int **graph, *book;
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
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[a][b] = 1;
	} 
	//��ʼ�����
	for (i = 0; i < n; i++) {
		book[i] = 0;
	} 
	//���������������
	dfs(0, graph, book); 
	return 0;
}
