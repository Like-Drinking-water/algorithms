#include <stdio.h>
#include <stdlib.h>

/***************************************
���⣺���� m �����Ҫ�ڳ� A + B = C ��
��ʽ����֪��
1.�Ӻ���ȺŸ��� 2 �����
2.0-9�ֱ��� 6, 2, 5, 5, 4, 5, 6, 3, 7, 6
�����
3.���еĻ�񶼱�������
�������ö�ٷ� 
****************************************/ 
/**
* ����һ��������Ҫ�õ��Ļ������
* @Param num Ҫ����ʹ�û������������ 
* @Return ������������õ��Ļ������ 
*/
int MatchNum(int num) {
	//������� 0 - 9 ÿ�������õ��Ļ���� 
	int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; 
	//��������һ�����˶��ٸ���� 
	int sum = 0;
	//������ 
	if (num < 0) {
		return -1;
	}
	do {
		sum += a[num % 10];
		num /= 10;
	} while (num != 0);
	return sum;
} 

/**
* ����a b��ȡ�������� 
*/
int maxNum(int m) {
	int i = (m - 4) / 4 - 1;
	int num = 1;
	for (;i > 0; i--) {
		num *= 10;
		num++;
	}
	return num;
}

int main(void) {
	int a, b, c, m;
	//a b��ȡ�������� 
	int max; 
	//��ʾһ���ж��ٸ���ʽ 
	int sum;
	//ʵ���������õ��Ļ������ 
	int real;
	//��ȡ��������
	scanf("%d", &m);
	real = m - 4; 
	//�����������
	max = maxNum(m);
	for (a = 0; a < max; a++) {
		for (b = 0; b < max; b++) {
			c = a + b;
			if (MatchNum(a) + MatchNum(b) + MatchNum(c) == real) {
				sum++;
				printf("%d + %d = %d\n", a, b, c);
			}
		} 
	}
	printf("Have : %d", sum);
	return 0;
}
