#include <stdio.h>
#include <stdlib.h>

/*********************************
���⣺�� 1 - n ����ȫ����
�����ʹ��������������㷨 
*********************************/
void dfs(int step, int n, int *a, int *book) {
	int i;
	//���վ�������һ������ 
	//˵��һ��������� 
	if (step == n) {
		//��һ�����н������ 
		for (i = 0; i < n; i++) {
			printf("%d", a[i]);
		} 
		printf("\n");
		return;
	}
	//���� 1 - n ��˳�������� 
	for (i = 1; i <= n; i++) {
		//book[i] == 1 ��ʾ�������� 
		if (book[i] == 1) {
			//�� i ����� step ������ 
			a[step] = i;
			book[i] = 0;
			//����һ������
			dfs(step + 1, n, a, book);
			//�ص���ǰ������ȡ������ 
			book[i] = 1; 
		}
	} 
	return; 
} 

int *initBook(int n, int *book) {
	int i;
	book = (int *)malloc((n + 1) * sizeof(int));
	//��ʼ�� book �е�ֵ 
	for (i = 0; i <= n; i++) {
		book[i] = 1;
	}
	return book;
}

int main(void) {
	int *a, *book, n;
	//������ٸ�ֵ 
	scanf("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	//��ʼ�� book 
	book = initBook(n, book);
	//�ӵ� 0 �����ӿ�ʼ�� 
	dfs(0, n, a, book);
	return 0;
}
