#include <stdio.h>
#include <stdlib.h>

/*******************************************************
���⣺ͼ�ı������ö�ά���鱣��ͼ�нڵ�Ĺ�ϵ��-1 ��ʾ�޷�
����;0 ��ʾ����Ϊ 0;1 ��ʾ���Ե���
�������������㷨 
********************************************************/

int main(void) {
	//ͼ�Ľڵ�����Լ����� 
	int n, m;
	//���������Լ���ʱ�洢����
	int i, j, a, b;
	//ͼ�Լ����
	int **graph, *book;
	//���� 
	int *q;
	int head = 0, tail = 0; 
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
	//��ʼ������
	q = (int *)malloc(sizeof(int) * n); 
	q[0] = 0;
	tail++;
	book[0] = 1;
	printf("�� 0 �Žڵ㿪ʼ����\n");
	while (head < tail) {
		for (i = 0; i < n; i++) {
			//������Ե�����һ��������һ����û���߹� 
			if (graph[q[head]][i] == 1 && book[i] == 0) {
				//��ӱ�Ǳ�ʾ�Լ��߹� 
				book[i] = 1;
				printf("�� %d �Žڵ�\n", i);
				q[tail] = i;
				tail++; 
			}
		}
		head++;
	}
	return 0;
}
