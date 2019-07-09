#include <stdio.h>
#include <stdlib.h>

/**********************************************
���⣺���ʽ��ֵ 
***********************************************/
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OK 1
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef struct {
	char *base;
	char *top;
	int stackSize;
} Stack; 

void initStack(Stack *s) {
	s->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!s->base) {
		//�ڴ����ʧ�� 
		exit(OVERFLOW);
	}
	s->top = s->base; 
	s->stackSize = STACK_INIT_SIZE;
}

int stackEmpty(Stack s) {
	return (s.base == s.top);
}

int push(Stack *s, char e) {
	if (s->top - s->base >= s->stackSize) {
		s->base = (char *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(char));
		if (!s->base) {
			//�ڴ����ʧ�� 
			exit(OVERFLOW);
		}
		s->top = s->base + s->stackSize;
		s->stackSize += STACKINCREMENT;
	}
	*(s->top) = e;
	s->top++;
}

int pop(Stack *s, char *e) {
	if (s->base == s->top) {
		return ERROR;
	}
	s->top--;
	*e = *(s->top);
	return OK;
}

char getTop(Stack s) {
	return *(s.top - 1);
}

//�ж��Ƿ��ǲ����� 
int isOPTR(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '#') {
		return TRUE;
	}
	else {
		return FALSE;
	}
} 

//���ȼ���ϵ
char precede(char o1, char o2) {
	if (o1 == '+') {
		if (o2 == '+') {
			return '>';
		}
		else if (o2 == '-') {
			return '>';
		}
		else if (o2 == '*') {
			return '<';
		}
		else if (o2 == '/') {
			return '<';
		}
		else if (o2 == '(') {
			return '<';
		}
		else if (o2 == ')') {
			return '>';
		}
		else {
			return '>';
		}
	}
	else if (o1 == '-') {
		if (o2 == '+') {
			return '>';
		}
		else if (o2 == '-') {
			return '>';
		}
		else if (o2 == '*') {
			return '<';
		}
		else if (o2 == '/') {
			return '<';
		}
		else if (o2 == '(') {
			return '<';
		}
		else if (o2 == ')') {
			return '>';
		}
		else {
			return '>';
		}
	}
	else if (o1 == '*') {
		if (o2 == '+') {
			return '>';
		}
		else if (o2 == '-') {
			return '>';
		}
		else if (o2 == '*') {
			return '>';
		}
		else if (o2 == '/') {
			return '>';
		}
		else if (o2 == '(') {
			return '<';
		}
		else if (o2 == ')') {
			return '>';
		}
		else {
			return '>';
		}
	}
	else if (o1 == '/') {
		if (o2 == '+') {
			return '>';
		}
		else if (o2 == '-') {
			return '>';
		}
		else if (o2 == '*') {
			return '>';
		}
		else if (o2 == '/') {
			return '>';
		}
		else if (o2 == '(') {
			return '<';
		}
		else if (o2 == ')') {
			return '>';
		}
		else {
			return '>';
		}
	}
	else if (o1 == '(') {
		if (o2 == '+') {
			return '<';
		}
		else if (o2 == '-') {
			return '<';
		}
		else if (o2 == '*') {
			return '<';
		}
		else if (o2 == '/') {
			return '<';
		}
		else if (o2 == '(') {
			return '<';
		}
		else if (o2 == ')') {
			return '=';
		}
		else {
			return '>';
		}
	}
	else if (o1 == ')') {
		if (o2 == '+') {
			return '>';
		}
		else if (o2 == '-') {
			return '>';
		}
		else if (o2 == '*') {
			return '>';
		}
		else if (o2 == '/') {
			return '>';
		}
		else if (o2 == ')') {
			return '>';
		}
		else {
			return '>';
		}
	}
	else {
		if (o2 == '+') {
			return '<';
		}
		else if (o2 == '-') {
			return '<';
		}
		else if (o2 == '*') {
			return '<';
		}
		else if (o2 == '/') {
			return '<';
		}
		else if (o2 == '(') {
			return '<';
		}
		else {
			return '=';
		}
	}
} 

char Operate(char a, char opt, char b) {
	if (opt == '+') {
		return a + b;
	}
	else if (opt == '-') {
		return a - b;
	}
	else if (opt == '*') {
		return a * b;
	} 
	else {
		return a / b;
	}
}

int main(void) {
	//������ջ�Լ�������ջ 
	Stack OPND, OPTR;
	char c;
	char opt;
	char a, b;
	c = getchar();
	initStack(&OPND);
	initStack(&OPTR);
	push(&OPTR, '#');
	while (c != '#' || getTop(OPTR) != '#') {
		//����ǲ���������������ջ 
		if (!isOPTR(c)) {
			push(&OPND, c - 48); 
			c = getchar();
		}
		else {
			switch (precede(getTop(OPTR), c)) {
				case '<':
					push(&OPTR, c);
					c = getchar();
					break;
				case '=':
					pop(&OPTR, &c);
					c = getchar();
					break;
				case '>':
					pop(&OPTR, &opt);
					pop(&OPND, &b);
					pop(&OPND, &a);
					push(&OPND, Operate(a, opt, b));
					break;
			}
		}
	}
	printf("%d", getTop(OPND));
	return 0;
}
