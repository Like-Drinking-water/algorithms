#include <stdio.h>
#include <stdlib.h>

/**************************************************
���⣺ͨ�������Ĺ�ϵ�ж������ж����� 
***************************************************/
//���������Ĺ�ϵ 
int f[100] = {0};
//���ٸ����Լ��������ϵ 
int n, m;

/**
* ��ʼ���˺���Ĺ�ϵ 
*/
void init() {
	int i;
	for (i = 0; i < n; i++) {
		f[i] = i;
	}
} 

/**
* �ҵ��鳤
* @param i �ڼ����� 
*/
int getFather(int i) {
	if (i == f[i]) {
		return i; 
	} 
	else {
		//�����е㶼ָ��һ�����ڵ� 
		f[i] = getFather(f[i]);
		return f[i];
	}
} 

/**
* �ϲ�������  
*/
void merge(int i, int j) {
	int t1, t2;
	t1 = getFather(i);
	t2 = getFather(j);
	//�����˲�ͬ�� 
	if (t1 != t2) {
		f[t2] = t1;
	}
}

int main(void) {
	int i, x, y;
	//ͳ��һ���ж����� 
	int sum = 0; 
	//��ȡ�ж��˸����Լ��������ϵ 
	scanf("%d %d", &n, &m);
	//��ʼ�� 
	init(); 
	//��ȡ��ϵ���ϲ��� 
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		merge(x, y);
	} 
	//��ȡ������ 
	for (i = 0; i < n; i++) {
		if (i == f[i]) {
			sum++; 
		}
	}
	//��ӡ��� 
	printf("%d", sum);
	return 0;
}
