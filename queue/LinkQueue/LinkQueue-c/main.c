#include <stdio.h>
#include <stdlib.h>

/*************************************
������ 
**************************************/

#define ElemType int
#define OVERFLOW -2
#define Status int
#define ERROR 0
#define OK 1

typedef struct  QNode {
	ElemType data;
	struct QNode *next;
} QNode;

typedef struct {
	QNode *front;
	QNode *rear;
} LinkQueue; 

void initQueue(LinkQueue *q) {
	q->front = (QNode *)malloc(sizeof(QNode));
	if (!q->front) {
		//�����ڴ�ʧ�� 
		exit(OVERFLOW);
	}
	q->rear = q->front;
	q->front->next = NULL; 
}

void destroyQueue(LinkQueue *q) {
	while (q->front) {
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	} 
}

void enQueue(LinkQueue *q, ElemType e) {
	QNode *p = (QNode *)malloc(sizeof(QNode));
	if (!p) {
		//�ڴ����ʧ��
		exit(OVERFLOW); 
	}
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p; 
}

Status deQueue(LinkQueue *q, ElemType *e) {
	QNode *p;
	if (q->front == q->rear) {
		return ERROR;
	}
	//��ȡ��ͷָ��ָ��ĵ�ַ 
	p = q->front->next;
	//�ö�ͷָ��ָ����һ��Ԫ�� 
	q->front->next = p->next;
	//��ȡԭ����ͷԪ�ص�ֵ 
	*e = p->data;
	//��������һ��Ԫ��
	//��βָ��ָ��ͷָ��ָ���λ��
	if (p == q->rear) {
		q->rear = q->front;
	} 
	//�ͷ�ԭ����ͷԪ�ص��ڴ�ռ�
	free(p); 
	return OK;
}

int main(int argc, char *argv[]) {
	return 0;
}
