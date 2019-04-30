/***************************
用桶排序来对成绩进行排序
***************************/

#include<stdio.h>
#define MAX_SCORE 10
#define STUDENT_NUMBER 5

int main(void) {
	//创建存放数据的桶
	int a[MAX_SCORE + 1];
	int i, j;
	//成绩
	int t;
	//初始化筒中的数据
	for (i = 0; i <= MAX_SCORE; i++) {
		a[i] = 0;
	}
	//循环输入成绩
	for (i = 0; i < STUDENT_NUMBER; i++) {
		scanf("%d",&t);
		a[t]++;
	}
	//按成绩从高到低打印
	for (i = MAX_SCORE; i >= 0; i--) {
		for (j = 0; j < a[i]; j++) {
			printf("%d ",i);
		}
	}
	return 0;
}