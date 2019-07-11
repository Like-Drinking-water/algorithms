#include <stdio.h>
#include <stdlib.h>

/*************************************
链队列 
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
		//分配内存失败 
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
		//内存分配失败
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
	//获取队头指针指向的地址 
	p = q->front->next;
	//让队头指针指向下一个元素 
	q->front->next = p->next;
	//获取原来队头元素的值 
	*e = p->data;
	//如果是最后一个元素
	//将尾指针指向头指针指向的位置
	if (p == q->rear) {
		q->rear = q->front;
	} 
	//释放原来队头元素的内存空间
	free(p); 
	return OK;
}

int main(int argc, char *argv[]) {
	return 0;
}
