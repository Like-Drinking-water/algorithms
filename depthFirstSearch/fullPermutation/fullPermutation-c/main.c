#include <stdio.h>
#include <stdlib.h>

/*********************************
���⣺�� 1 - n ����ȫ����
�����ʹ��������������㷨 
*********************************/
/**
* ���������������
* @Param step ��ʾ��ǰλ���ĸ�����
* @Param n ��ʾ�ж��ٸ���
* @Param a ��ʾ����
* @Param book ��ʾ���Ʊ�ǣ�1 ��ʾ�� 0 ��ʾû�� 
*/ 
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

/**
* ��ʼ�� book
* @Param n ��ʾ�ж��ٸ�����Ҫ��� 
* @Return ���س�ʼ����ɵ� book 
*/
int *initBook(int n) {
	int *book 
	int i;
	book = (int *)malloc((n + 1) * sizeof(int));
	//��ʼ�� book �е�ֵ 
	for (i = 1; i <= n; i++) {
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
	book = initBook(n);
	//�ӵ� 0 �����ӿ�ʼ��
	dfs(0, n, a, book);
	return 0;
}
