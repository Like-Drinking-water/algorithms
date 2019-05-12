#include <stdio.h>
#include <malloc.h>

/*****************************
问题：买书记录ISBN号去重并排序
解决方式二：冒泡排序 
******************************/

int main() {
	//假设最多有 100 个人进行登记买书
	int *a, i, j, n, t, tmp;
	//获取要买书的人数
	scanf("%d",&n);
	a = (int *)malloc(sizeof(int) * n);
	//获取要买的书的 ISBN 号 
	for (i = 0; i < n; i++) {
		scanf("%d",&t);
		a[i] = t;
	} 
	//进行冒泡排序
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i; j++) {
			if (a[j] > a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		} 
	} 
	//进行输出
	for (i = 0; i < n; i++) {
		if (a[i] != a[i + 1]) {
			printf("%d ", a[i]);
		}
	} 
	 
	return 0;
}
