#include <stdio.h>
#include <stdlib.h>

/*******************************************
��ȡ��С������ 
*******************************************/ 

int main(void) {
	//��Ƕ����Ƿ��Ѿ����������� ͼ 
	int book[6], graph[6][6];
	//��������������������ľ��� 
	int dis[6];
	//�����������Ĵ�С 
	int sum = 0;
	//��� int ֵ ��Ϊ������ֵ 
	int inf = 214783647;
	int i, j, k, a, b, c, count = 0;
	//��Сֵ 
	int min; 
	//�ж��ٸ������Լ��������� 
	int n, m;
	//��ȡ�������ͱ���
	scanf("%d %d", &n, &m); 
	
	//��ʼ�����
	for (i = 0; i < n; i++) {
		book[i] = 0;
	} 
	//��ʼ��ͼ 
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) {
				graph[i][j] = 0;
			} else {
				graph[i][j] = inf;
			}
		}
	}
	//��ȡͼ
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
		graph[b][a] = c;
	} 
	//��ʼ������������������ľ���
	for (i = 0; i < n; i++) {
		dis[i] = graph[0][i];
	} 
	//������ 0 ���뵽��С��������
	book[0] = 1;
	count++;
	while (count < n) {
		//�ҵ�������������Ķ��� 
		min = inf; 
		for (i = 0; i < n; i++) {
			if (book[i] == 0 && dis[i] < min) {
				min = dis[i];
				j = i;
			}
		}
		book[j] = 1;
		count++;
		sum += min;
		//�����ɳ� 
		for (i = 0; i < n; i++) {
			if (book[i] == 0 && dis[i] > graph[i][j]) {
				dis[i] = graph[i][j];
			}
		} 
	}
	printf("%d", sum);
	return 0;
}
