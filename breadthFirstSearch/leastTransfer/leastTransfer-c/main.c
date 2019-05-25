#include <stdio.h>
#include <stdlib.h>

/******************************************************
���⣺��ͼ����ʾ��ͬ��վ��1 ��ʾ����վ���Ի��ൽ�-1 
��ʾ����վ����ֱ�ӵ��0 ��ʾͬһ���㣬��Ҫ��������
���յ����ٻ��˵�·�� 
�������������㷨 
*******************************************************/ 
typedef struct {
	int node;
	int before;
} QNode;

int main(void) {
	//ͼ�нڵ��Լ����������� 
	int n, m;
	//���վ���յ�վ
	int start, end;
	//��������·�ߵ�ͼ���Ѿ���������·��
	int **graph, *book;
	//���������Լ���ʱ�洢����
	int i, j, a, b; 
	//����Ƿ��ҵ��յ� 
	int flag;
	//·�� 
	int *path;
	//����
	QNode *q;
	int head, tail;
	//��ȡ�ڵ�������Լ��������������յ� 
	scanf("%d %d %d %d", &n, &m, &start, &end); 
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
	//��·������ռ�
	path = (int *)malloc(sizeof(int) * n); 
	//��ʼ������
	q = (QNode *)malloc(sizeof(QNode) * n);
	head = 0;
	tail = 0;
	//����㿪ʼ���й����������
	book[start] = 1;
	q[tail].node = start;
	q[tail].before = -1;
	tail++;
	while(head < tail) {
		for (i = 0; i < n; i++) {
			//����ܵ���õ��Ҹõ�û���߹� 
			if (graph[q[head].node][i] == 1 && book[i] == 0) {
				q[tail].node = i;
				q[tail].before = head;
				tail++; 
				//�ҵ��յ㼴���˳� 
				if (i == end) {
					flag = 1;
					break;
				}
				book[i] = 1;
			} 
		}
		head++;
		if (flag) {
			break;
		} 
	} 
	//��·���ܹ������յ� 
	if (flag) {
		i = tail - 1;
		j = 0;
		//��ȡ·�� 
		while (i != -1) {
			path[j] = q[i].node;
			j++;
			i = q[i].before;
		}
		//��ӡ·�� 
		while (j > 1) {
			j--;
			printf("%d -> ", path[j]);
		}
		printf("%d", end);
	} 
	//û��·���ܹ������յ� 
	else {
		printf("û��·���ܹ������յ�"); 
	} 
	return 0;
}
