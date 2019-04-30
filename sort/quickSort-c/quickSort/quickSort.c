/****************
***快速排序******
****************/
#include<stdio.h>
#define LENGTH 10

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void quickSort(int a[], int left, int right) {
	int base, max, min;
	//左指针一定要小于右指针
	if (left >= right) {
		return;
	}
	//设置基值
	base = a[left];
	//设置左到右的最大值
	max = right;
	//设置左到右的最小值
	min = left;
	while(right != left) {
		//右指针从右到左查找小于基值的数，找到后停下来
		while (a[right] >= base && right > left) {
			right--;
		}
		//左指针从左到右查找大于基值的数
		while (a[left] <= base && right > left) {
			left++;
		}
		//如果左右指针没有相遇,将两个数值进行交换
		if (right > left) {
			swap(&a[left],&a[right]);
		}
	}
	//交换基值位置
	swap(&a[min],&a[left]);
	//通过递归进行继续排序
	quickSort(a, min, left - 1);
	quickSort(a, left + 1, max);
	return;
}

int main(void) {
	int a[LENGTH], i;
	//填入数据
	for (i = 0; i < LENGTH; i++) {
		scanf("%d",&a[i]);
	}
	//快排
	quickSort(a, 0, LENGTH - 1);
	//显示结果
	for (i = 0; i < LENGTH; i++) {
		printf("%d ",a[i]);
	}
	return 0;
}