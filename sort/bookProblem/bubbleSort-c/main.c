#include <stdio.h>
#include <malloc.h>

/*****************************
���⣺�����¼ISBN��ȥ�ز�����
�����ʽ����ð������ 
******************************/

int main() {
	//��������� 100 ���˽��еǼ�����
	int *a, i, j, n, t, tmp;
	//��ȡҪ���������
	scanf("%d",&n);
	a = (int *)malloc(sizeof(int) * n);
	//��ȡҪ������ ISBN �� 
	for (i = 0; i < n; i++) {
		scanf("%d",&t);
		a[i] = t;
	} 
	//����ð������
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i; j++) {
			if (a[j] > a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		} 
	} 
	//�������
	for (i = 0; i < n; i++) {
		if (a[i] != a[i + 1]) {
			printf("%d ", a[i]);
		}
	} 
	 
	return 0;
}
