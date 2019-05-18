#include <stdio.h>
#include <stdlib.h>

/**************************************************** 
����: _ _ _ + _ _ _ = _ _ _ ���� 1 - 9 ����ʹ��ʽ����
ÿ����ֻ�ܳ���һ��
���: ʹ������������� 
*****************************************************/
//����ͳ���ж��ٸ���ʽ 
int total = 0;

/**
* ���������������
* @Param step ��ʾ��ǰλ���ĸ�����
* @Param n ��ʾ�ж��ٸ���
* @Param a ��ʾ����
* @Param book ��ʾ���Ʊ�ǣ�1 ��ʾ�� 0 ��ʾû�� 
*/ 
void dfs(int step, int n, int *a, int *book) {
	int i;
	//��ʾ�Ѿ�ǰ��ĺ����Ѿ������� 
	if (step == n) {
		//������Ͻ����������� 
		if (a[0] * 100 + a[1] * 10 + a[2] + a[3] * 100 + a[4] * 10 + a[5] ==
		a[6] * 100 + a[7] * 10 + a[8]) {
			printf("%d%d%d + %d%d%d = %d%d%d\n", a[0], a[1], a[2], a[3], a[4],
			a[5], a[6], a[7], a[8]);
			total++; 
		}
		//�˻�ǰһ������ 
		return;
	}
	//�������з������� 
	for (i = 1; i <= n; i++) {
		//�������� 
		if (book[i] == 1) {
			//�����Ʒŵ������� 
			a[step] = i;
			book[i] = 0; 
			//����ȥ������һ������
			dfs(step + 1, n, a, book);
			//�������ջ� 
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
	int *book, i;
	book = (int *)malloc((n + 1) * sizeof(int));
	for (i = 1; i <= n; i++) {
		book[i] = 1;
	}
	return book;
}

int main(void) {
	int *a, *book;
	//��ʼ������������ 
	a = (int *)malloc(9 * sizeof(int));
	book = initBook(9);
	//�ӵ�һ�����ӿ�ʼ����
	dfs(0, 9, a, book);
	printf("Have : %d", total >> 1);
	return 0;
}
