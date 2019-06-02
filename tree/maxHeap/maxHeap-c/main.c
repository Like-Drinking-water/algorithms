#include <stdio.h>
#include <stdlib.h>

/********************** 
使用最大堆进行堆排序 
**********************/
//用来作为放堆的数组 
int heap[101];
//用来表示堆中元素的个数 
int n; 

//交换堆中两个元素的值 
void swap(int x, int y) {
	int tmp;
	tmp = heap[x];
	heap[x] = heap[y];
	heap[y] = tmp;
} 
/**
* 向下调整元素 
* @param i 在堆中的编号 
*/
void siftDown(int i) {
	//标记是否已经调整好 
	int flag = 0; 
	int tmp;
	while (i * 2 <= n && flag == 0) {
		//父节点比左儿子小 
		if (heap[i] < heap[i * 2]) {
			tmp = i * 2;
		} 
		//父节点比左儿子大
		else {
			tmp = i;
		}
		//表示有右儿子 
		if (i * 2 + 1 <= n) {
			//获取较大值的下标 
			if (heap[tmp] < heap[i * 2 + 1]) {
				tmp = i * 2 + 1;
			} 
		}
		//表示父节点不是较大值 需要调整 
		if (tmp != i)  {
			swap(tmp, i); 
			i = tmp;
		} 
		//表示已经是较大值了 
		else {
			flag = 1;
		}
	} 
} 

/**
* 进行堆排序 每次把堆顶元素放到数组的最后 
*/
void heapSort() {
	while (n > 1) {
		swap(1, n);
		n--;
		siftDown(1);
	}
} 

/**
* 创建堆 
*/
void createHeap() {
	int i;
	//从最后一个非叶结点到第一个结点一次进行向下调整 
	for (i = n / 2; i >= 1; i--) {
		siftDown(i); 
	} 
}

int main(void) {
	//表示要存到堆中元素的数量 
	int num;
	int i;
	scanf("%d", &num);
	for (i = 1; i <= num; i++) {
		scanf("%d", &heap[i]);
	}
	n = num; 
	//创建堆 
	createHeap();
	//进行排序
	heapSort();
	//打印结果 
	for (i = 1; i <= num; i++) {
		printf("%d ", heap[i]);
	} 
	return 0;
}
