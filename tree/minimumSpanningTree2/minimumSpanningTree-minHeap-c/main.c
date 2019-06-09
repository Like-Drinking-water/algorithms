#include <stdio.h>
#include <stdlib.h>

/****************************************
��С����������(ͨ����С�ѽ����Ż�) 
*****************************************/
//�� 
int heap[10], size;
//�����ڶ��е�λ�� 
int pos[10];
//����������������ľ��� 
int dis[10]; 

void swap(int i, int j) {
	int tmp;
	//�������ж����λ�� 
	tmp = heap[i];
	heap[i] = heap[j];
	heap[j] = tmp;
	//�޸ļ�¼���ж����λ��
	tmp = pos[heap[i]];
	pos[heap[i]] = pos[heap[j]];
	pos[heap[j]] = tmp;
} 

void siftDown(int i) {
	//����Ƿ���Ҫ�������� 
	int flag = 0;
	int tmp;
	while (i * 2 <= size && flag == 0) {
		//�����������ӱ���С 
		if (dis[heap[i * 2]] < dis[heap[i]]) {
			tmp = i * 2;
		}
		//����������������С 
		else {
			tmp = i;
		}
		//��������Ҷ��� 
		if (i * 2 + 1 <= size) {
			//��������Ҷ��ӱ���С
			if (dis[heap[i * 2 + 1]] < dis[heap[i]]) {
				tmp = i * 2 + 1;
			} 
		} 
		//��������������Ӷ�С˵�������������� 
		if (tmp == i) {
			flag = 1;
		} 
		//�����û�������
		//�����С�Ķ��ӽ���λ��
		//���Խ�����λ�ý�����һ�ε��� 
		else {
			swap(i, tmp);
			i = tmp;
		}
	} 
}

void siftUp(int i) {
	//����Ƿ������� 
	int flag = 0;
	//����ǶѶ����������
	if (i == 1) {
		return;
	} 
	//���е���
	while (i != 1 && flag == 0) {
		//������ĸ��ױ����� �����丸�׽���λ�� 
		if (dis[heap[i]] < dis[heap[i / 2]]) {
			swap(i, i / 2); 
		}
		//����˵���Ѿ�������� 
		else {
			flag = 1; 
		} 
		i = i / 2;
	} 
	
} 

int pop() {
	int i;
	i = heap[1];
	heap[1] = heap[size];
	pos[heap[1]] = 1;
	size--;
	siftDown(1);
	return i;
}

int main(void) {
	//����ͼ����Ϣ 
	int u[20], v[20], w[20];
	//�ڽӱ� 
	int next[20], first[20];
	//�������Լ����� 
	int n, m;
	//��¼�����������Ķ������� 
	int count = 0;
	//��� int ֵ ��Ϊ������ֵ 
	int inf = 214783647;
	//�������Ĵ�С
	int sum = 0; 
	int i, j;
	//����Ƿ��Լ����������� 
	int book[20];
	//��ȡ�������Լ�����
	scanf("%d %d", &n, &m);
	//��ʼ�����
	for (i = 1; i <= n; i++) {
		book[i] = 0;
	} 
	//��ȡͼ
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	} 
	for (i = 1; i <= m; i++) {
		u[i + m] = v[i];
		v[i + m] = u[i];
		w[i + m] = w[i]; 
	}
	//�����ڽӱ�
	for (i = 1; i <= n; i++) {
		first[i] = -1;
	} 
	for (i = 1; i <= 2 * m; i++) {
		next[i] = first[u[i]];
		first[u[i]] = i;
	}
	//�� 1 �Ŷ������������
	book[1] = 1;
	count++;
	//��ʼ������������������ľ��� 
	dis[1] = 0;
	for (i = 2; i <= n; i++) {
		dis[i] = inf;
	}
	i = first[1];
	while (i != -1) {
		dis[v[i]] = w[i];
		i = next[i];
	} 
	//��ʼ����
	size = n;
	for (i = 1; i <= n; i++) {
		heap[i] = i;
		pos[i] = i;
	} 
	for (i = n / 2; i > 0; i--) {
		siftDown(i);
	}
	//��һ�Ŷ������ 
	pop();
	while (count < n) {
		//��ȡ�Ѷ��Ķ��� 
		i = pop();
		book[i] = 1;
		count++;
		sum += dis[i]; 
		//�����ö�������б� 
		j = first[i];
		while (j != -1) {
			//�����ɳ� 
			if (book[v[j]] == 0 && dis[v[j]] > w[j]) {
				dis[v[j]] = w[j];
				siftUp(pos[v[j]]);
			}
			j = next[j];
		}
	} 
	printf("%d", sum);
	return 0;
}
