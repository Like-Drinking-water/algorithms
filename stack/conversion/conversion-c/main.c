#include <stdio.h>
#include <stdlib.h>

/**********************************************
问题：十进制转其他进制
输入一个十进制数以及要转换的进制进行转换 
***********************************************/
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OK 1
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef struct {
	int *base;
	int *top;
	int stackSize;
} Stack; 

void initStack(Stack *s) {
	s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!s->base) {
		//内存分配失败 
		exit(OVERFLOW);
	}
	s->top = s->base; 
	s->stackSize = STACK_INIT_SIZE;
}

int stackEmpty(Stack s) {
	return (s.base == s.top);
}

int push(Stack *s, int e) {
	if (s->top - s->base >= s->stackSize) {
		s->base = (int *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(int));
		if (!s->base) {
			//内存分配失败 
			exit(OVERFLOW);
		}
		s->top = s->base + s->stackSize;
		s->stackSize += STACKINCREMENT;
	}
	*(s->top) = e;
	s->top++;
}

int pop(Stack *s, int *e) {
	if (s->base == s->top) {
		return ERROR;
	}
	s->top--;
	*e = *(s->top);
	return OK;
}

int main(void) {
	//十进制数以及要转换的进制 
	int N, d;
	int e;
	Stack s;
	initStack(&s);
	scanf("%d %d", &N, &d);
	while(N) {
		push(&s, N % d);
		N /= d;
	} 
	while(!stackEmpty(s)) {
		pop(&s, &e);
		printf("%d", e);
	}
	return 0;
}
