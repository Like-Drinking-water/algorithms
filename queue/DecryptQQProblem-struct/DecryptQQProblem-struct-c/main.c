#include <stdio.h>
#include <stdlib.h>

/******************************************** 
���⣺���� qq ��, ���ܷ��������� qq ��
�ĵ�һ����ɾ�������ڶ�λ�Ƶ����һλ
ѭ��������ֱ��ֻʣ���һλ�������һλҲɾ����
ɾ����˳����� qq ��  
�����ͨ������ 
*********************************************/ 

struct queue {
	//���е��������� 
	int data[20];
	//�����е�ͷָ�� 
	int head;
	//�����е�βָ�� 
	int tail;
}; 

int main(void) {
	struct queue q;
	int i;
	//��ʼ������ 
	q.head = 0;
	q.tail = 0;
	for (i = 0; i < 9; i++) {
		scanf("%d", &q.data[i]);
		q.tail++;
	}
	//���н���
	while (q.head < q.tail) {
		//��Ҫɾ������������� 
		printf("%d", q.data[q.head]);
		q.head++;
		//���ڶ������ŵ����е����
		q.data[q.tail] = q.data[q.head];
		q.tail++;
		q.head++; 
	}  
	return 0;
}
