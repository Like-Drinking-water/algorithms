#include <stdio.h>

/*****************************
���⣺�����¼ISBN��ȥ�ز�����
�����ʽһ��Ͱ���� 
******************************/

int main() {
	//���� ISBN �ŵ�Ϊ 0 - 1000 
	//n ��ʾ�� n ���˵Ǽ����� 
	//t ��ʾ��� ISBN �� 
	int a[1001], i, n, t; 
	//��������г�ʼ�� 
	for (i = 0; i < 1001; i++) {
		a[i] = 0;
	}
	//��ȡҪ���������
	scanf("%d",&n);
	//�����ȡҪ������ ISBN ��
	for (i = 0; i < n; i++) {
		scanf("%d",&t);
		a[t] = 1;
	} 
	//չʾ��� 
	for (i = 0; i < 1001; i++) {
		if (a[i] == 1) {
			printf("%d ", i);
		} 
	}
	return 0;
}