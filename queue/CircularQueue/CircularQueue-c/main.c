#include <stdio.h>
#include <stdlib.h>

/********************************
循环队列 
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
		//分配内存失败 
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
		//队满 
		return ERROR;
	}
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
	return OK; 
}

Status deQueue(CircularQueue *q, ElemType *e) {
	if ((q->front + 1) % MAXSIZE == q->rear) {
		//空队
		return ERROR; 
	}  
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return OK; 
}

int main(int argc, char *argv[]) {
	return 0;
}
