#include <stdio.h>
#include <stdlib.h>

/********************************
ѭ������ 
*********************************/

#define MAXSIZE 100
#define ERROR 0
#define OK 1 
#define ElemType int
#define OVERFLOW -2 
#define Status int

typedef struct {
	ElemType *base;
	int front;
	int rear;
} CircularQueue;

void initQueue(CircularQueue *q) {
	q->base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	if (!q->base) {
		//�����ڴ�ʧ�� 
		exit(OVERFLOW);
	}
	q->front = 0;
	q->rear = 0;
}

int queueLength(CircularQueue q) {
	return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

Status enQueue(CircularQueue *q, ElemType e) {
	if ((q->rear + 1) % MAXSIZE == q->front) {
		//���� 
		return ERROR;
	}
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
	return OK; 
}

Status deQueue(CircularQueue *q, ElemType *e) {
	if ((q->front + 1) % MAXSIZE == q->rear) {
		//�ն�
		return ERROR; 
	}  
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return OK; 
}

int main(int argc, char *argv[]) {
	return 0;
}
