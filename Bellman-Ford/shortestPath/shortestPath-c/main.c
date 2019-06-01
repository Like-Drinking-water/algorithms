#include <stdio.h>
#include <stdlib.h>

/****************************************************
���⣺�����Դ���·��(����Ȩ)
�����ʹ�� Bellman-Ford �㷨 
****************************************************/

int main(void) {
	//����Ƿ��ɳ���ɻ��м�⸺Ȩ��· 
	int flag;
	//int ���ֵ
	int inf = 214783647; 
	//�ֱ��ʾ��㣬�յ��Ȩֵ 
	int *u, *v, *w;
	//��¼��Ԫ���·�� 
	int *dis;
	//��ʾ�м������� �Ѿ�������
	int n, m, s;
	//��������
	int i, j; 
	//��ȡ���������������� 
	scanf("%d %d %d", &n, &m, &s);
	//��ʼ��ͼ
	u = (int *)malloc(sizeof(int) * m);
	v = (int *)malloc(sizeof(int) * m);
	w = (int *)malloc(sizeof(int) * m); 
	//��ȡͼ��Ϣ
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	}
	//��ʼ����Դ���·��
	dis = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		if (i == s) {
			dis[s] = 0;
		} else {
			dis[i] = inf;
		}
	}
	//Bellman-Ford �㷨���Ĵ���
	for (i = 0; i < n - 1; i++) {
		flag = 0; 
		for (j = 0; j < m; j++) {
			if (dis[u[j]] < inf && dis[v[j]] > dis[u[j]] + w[j]) {
				dis[v[j]] = dis[u[j]] + w[j];
				flag = 1;
			}
		}
		//��ʾ�ɳ���� 
		if (!flag) {
			break;
		}
	} 
	//��⸺Ȩ��· 
	flag = 0;
	for (i = 0; i < m; i++) {
		if (dis[u[i]] < inf && dis[v[i]] > dis[u[i]] + w[i]) {
			dis[v[i]] = dis[u[i]] + w[i];
			flag = 1;
		}
	} 
	if (flag) {
		printf("��ͼ���и�Ȩ��·");
	}
	//��ӡ���
	for (i = 0; i < n; i++) {
		printf("%d ", dis[i]);
	} 
	return 0;
}
