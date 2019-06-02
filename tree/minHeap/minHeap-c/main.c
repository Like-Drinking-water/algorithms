#include <stdio.h>
#include <stdlib.h>

/*********************************************
���⣺������С�ѣ��������ȡ�Ѷ�Ԫ��
**********************************************/
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
		//���ڵ������Ӵ� 
		if (heap[i] > heap[i * 2]) {
			tmp = i * 2;
		} 
		//���ڵ�������С 
		else {
			tmp = i;
		}
		//��ʾ���Ҷ��� 
		if (i * 2 + 1 <= n) {
			//��ȡ��Сֵ���±� 
			if (heap[tmp] > heap[i * 2 + 1]) {
				tmp = i * 2 + 1;
			} 
		}
		//��ʾ���ڵ㲻�ǽ�Сֵ ��Ҫ���� 
		if (tmp != i)  {
			swap(tmp, i); 
			i = tmp;
		} 
		//��ʾ�Ѿ��ǽ�Сֵ�� 
		else {
			flag = 1;
		}
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

/**
* ɾ���Ѷ�Ԫ�ز�����
* @return �Ѷ�Ԫ�� 
*/ 
int deleteTop() {
	int tmp;
	tmp = heap[1];
	//�����һ��Ԫ�ظ��ǵ���һ��Ԫ�� 
	heap[1] = heap[n];
	n--;
	siftDown(1);
	return tmp;
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
	//���ɾ���Ѷ�Ԫ��
	for (i = 1; i <= num; i++) {
		printf("%d ", deleteTop());
	} 
	 
	return 0;
}
