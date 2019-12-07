#include <stdio.h>
#include <stdlib.h>

/*******************************
后序遍历二叉树 
*******************************/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define LEFT 0
#define RIGHT 1 
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef int ElemType;
typedef int Status; 

//二叉树的存储结构
typedef struct BiTreeNode {
	ElemType data;
	struct BiTreeNode *lchild, *rchild, *parent;
} BiTreeNode, BiTree; 

//栈
typedef struct {
	BiTreeNode **top, **base;
	int stacksize;
} Stack; 

//初始化栈 
Status initStack(Stack *s) {
	s->top = (BiTreeNode **)malloc(sizeof(BiTreeNode *) * STACK_INIT_SIZE);
	if (!s->top) {
		exit(OVERFLOW);
	}
	s->base = s->top;
	s->stacksize = STACK_INIT_SIZE; 
	return OK; 
}



Status push(Stack *s, BiTreeNode *t) {
	int count;
	BiTreeNode **newbase;
	count = s->top - s->base;
	if (count >= s->stacksize) {
		newbase = (BiTreeNode **)realloc(s->base, sizeof(BiTreeNode *) * (s->stacksize + STACKINCREMENT));
		if (!newbase) {
			exit(OVERFLOW);
			s->base = newbase;
			s->top = s->base + count;
			s->stacksize += STACKINCREMENT;
		}
	} 
	*(s->top) = t;
	s->top++;
	return OK;
} 

Status stackEmpty(Stack s) {
	if (s.top == s.base) {
		return TRUE;
	}
	else {
		return FALSE; 
	} 
}

Status pop(Stack *s, BiTreeNode *t) {
	if (stackEmpty(*s)) {
		return ERROR;
	}
	s->top--; 
	if (*(s->top)) {
		*t = **(s->top);
	}
	return OK;
}

Status getTop(Stack s, BiTreeNode *t) { 
	if (stackEmpty(s))  {
		return ERROR;
	} 
	if (*(s.top - 1))  {
		*t = **(s.top - 1);
	}
	else {
	 	return FALSE; 
	} 
	return OK;
}

//创建一个空树
Status createBiTree(BiTree *t) {
	
	if (!t) {
		exit(OVERFLOW);
	}
	t->data = 0;
	t->parent = NULL;
	t->lchild = NULL;
	t->rchild = NULL;
	return OK;
}

//添加元素 
Status addChild(BiTreeNode *t, ElemType value, int direction) {
	BiTreeNode *tmp;
	tmp = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	if (!tmp) {
		exit(OVERFLOW);
	}
	tmp->data = value;
	tmp->parent = t;
	tmp->lchild = NULL;
	tmp->rchild = NULL;
	if (direction) {
		t->rchild = tmp;
	}
	else {
		t->lchild = tmp;
	}
	return OK;
}

//访问操作
Status visit(BiTreeNode *t) {
	printf("%d ", t->data);
	return OK;
} 


//中序遍历二叉树 
Status InOrderTraverse1(BiTree *t, Status (*visit)(BiTreeNode *t)) {
	if (t) {
		if (InOrderTraverse1(t->lchild, visit)) {
			if (visit(t)) {
				if (InOrderTraverse1(t->rchild, visit)) {
					return OK;
				}
			} 
			return ERROR;
		}
	}
	else {
		return OK;
	}
}

//中序遍历二叉树 
Status InOrderTraverse2(BiTree t) {
	Stack s;
	BiTreeNode *p;
	initStack(&s);
	push(&s, &t);
	p = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	while (!stackEmpty(s)) {
		while (getTop(s, p)) {
			push(&s, p->lchild);
		}
		//推出空指针 
		pop(&s, p);
		if (!stackEmpty(s)) {
			pop(&s, p);
			if (!visit(p)) {
				return ERROR;
			}
			push(&s, p->rchild);
		} 
	}
	return OK;
}

//中序遍历二叉树 
Status InOrderTraverse3(BiTree t) {
	Stack s;
	BiTreeNode *p;
	initStack(&s);
	p = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	*p = t;
	while (p || !stackEmpty(s)) {
		if (p) {
			push(&s, p);
			p = p->lchild;
		}
		else {
			p = (BiTreeNode *)malloc(sizeof(BiTreeNode));
			pop(&s, p);
			if (!visit(p)) {
				return ERROR;
			}
			p = p->rchild; 
		}
	}
	return OK;
}

int main(void) {
	BiTree *t;
	BiTreeNode *tmp;
	int i;
	t = (BiTree *)malloc(sizeof(BiTreeNode));
	createBiTree(t);
	addChild(t, 1, 0);
	addChild(t, 2, 1);
	tmp = t->lchild;
	addChild(tmp, 3, 0);
	addChild(tmp, 4, 1);
	InOrderTraverse1(t, visit);
	printf("\n");
	InOrderTraverse2(*t);
	printf("\n");
	InOrderTraverse3(*t);
	return 0;
}

