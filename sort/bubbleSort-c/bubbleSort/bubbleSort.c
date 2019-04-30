/***********************
****使用冒泡法排序******
************************/
#include<stdio.h>

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void) {
	int a[100], i, j, n, t;
	//输入一个数确定要输入数的个数
	scanf("%d", &n);
	//将数据进行存储
	for (i = 0; i < n; i++) {
		scanf("%d",&t);
		a[i] = t;
	}
	//进行冒泡排序(从大到小)
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i; j++) {
			if (a[j] < a[j + 1]) {
				swap(&a[j],&a[j + 1]);
			}
		}
	}
	//显示结果
	for (i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	return 0;
}