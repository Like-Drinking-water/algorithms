#include <stdio.h>
#include <stdlib.h>

/****************************************************
���⣺�����Դ���·��(����Ȩ)
�����ʹ�� Bellman-Ford �㷨(ʹ�ö��н����Ż�) 
****************************************************/

int main(void) {
	//��� int ֵ ��Ϊ������ֵ 
	int inf = 214783647;
	//�ڽӱ�
	int *first, *next;
	//����յ��Լ�Ȩֵ 
	int *u, *v, *w; 
	//���ĳ���ڵ��Ƿ��Ѿ�������� 
	int *book;
	//����
	int queue[100], head, tail;
	//��¼��Դ���·��
	int *dis;
	//�ڵ�����Լ�������� 
	int n, m, s; 
	//��������
	int i, j, k; 
	//��ȡ�ڵ���������Լ����
	scanf("%d %d %d", &n, &m, &s);
	//��ʼ����Դ���·��
	dis = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		if (i == s) {
			dis[i] = 0;
		} else {
			dis[i] = inf;
		}
	} 
	//��ʼ���ڽӱ�
	u = (int *)malloc(sizeof(int) * m); 
	v = (int *)malloc(sizeof(int) * m);
	w = (int *)malloc(sizeof(int) * m);
	first = (int *)malloc(sizeof(int) * n);
	next = (int *)malloc(sizeof(int) * m);
	//��ʼ�� 
	for (i = 0; i < n; i++) {
		first[i] = -1; 
	}
	//��ȡͼ������
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		next[i] = first[u[i]];
		first[u[i]] = i;
	} 
	//��ʼ�����
	book = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		book[i] = 0;
	} 
	//��ʼ������
	head = 0;
	tail = 0;
	//������������в��������� 
	queue[tail] = s;
	tail++;
	book[s] = 1; 
	while (head < tail) {
		k = first[queue[head]];
		while (k != -1) {
			if (dis[v[k]] > dis[u[k]] + w[k]) {
				dis[v[k]] = dis[u[k]] + w[k];
				//��û����� 
				if (book[v[k]] == 0) {
					queue[tail] = v[k];
					tail++;
					book[v[k]] = 1;
				}
			}
			k = next[k];
		}
		//����
		book[queue[head]] = 0;
		head++;
	} 
	//��ӡ��� 
	for (i = 0; i < n; i++) {
		printf("%d ", dis[i]);
	} 
	return 0;
}
