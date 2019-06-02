#include <stdio.h>
#include <stdlib.h>

/********************** 
ʹ�����ѽ��ж����� 
**********************/
//������Ϊ�Ŷѵ����� 
int heap[101];
//������ʾ����Ԫ�صĸ��� 
int n; 

//������������Ԫ�ص�ֵ 
void swap(int x, int y) {
	int tmp;
	tmp = heap[x];
	heap[x] = heap[y];
	heap[y] = tmp;
} 
/**
* ���µ���Ԫ�� 
* @param i �ڶ��еı�� 
*/
void siftDown(int i) {
	//����Ƿ��Ѿ������� 
	int flag = 0; 
	int tmp;
	while (i * 2 <= n && flag == 0) {
		//���ڵ�������С 
		if (heap[i] < heap[i * 2]) {
			tmp = i * 2;
		} 
		//���ڵ������Ӵ�
		else {
			tmp = i;
		}
		//��ʾ���Ҷ��� 
		if (i * 2 + 1 <= n) {
			//��ȡ�ϴ�ֵ���±� 
			if (heap[tmp] < heap[i * 2 + 1]) {
				tmp = i * 2 + 1;
			} 
		}
		//��ʾ���ڵ㲻�ǽϴ�ֵ ��Ҫ���� 
		if (tmp != i)  {
			swap(tmp, i); 
			i = tmp;
		} 
		//��ʾ�Ѿ��ǽϴ�ֵ�� 
		else {
			flag = 1;
		}
	} 
} 

/**
* ���ж����� ÿ�ΰѶѶ�Ԫ�طŵ��������� 
*/
void heapSort() {
	while (n > 1) {
		swap(1, n);
		n--;
		siftDown(1);
	}
} 

/**
* ������ 
*/
void createHeap() {
	int i;
	//�����һ����Ҷ��㵽��һ�����һ�ν������µ��� 
	for (i = n / 2; i >= 1; i--) {
		siftDown(i); 
	} 
}

int main(void) {
	//��ʾҪ�浽����Ԫ�ص����� 
	int num;
	int i;
	scanf("%d", &num);
	for (i = 1; i <= num; i++) {
		scanf("%d", &heap[i]);
	}
	n = num; 
	//������ 
	createHeap();
	//��������
	heapSort();
	//��ӡ��� 
	for (i = 1; i <= num; i++) {
		printf("%d ", heap[i]);
	} 
	return 0;
}
