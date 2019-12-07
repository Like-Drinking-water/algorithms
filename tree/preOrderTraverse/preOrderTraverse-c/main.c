#include <stdio.h>
#include <stdlib.h>

/*******************************
先序遍历二叉树 
*******************************/
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LEFT 0
#define RIGHT 1 

typedef int ElemType;
typedef int Status; 

//二叉树的存储结构
typedef struct BiTreeNode {
	ElemType data;
	struct BiTreeNode *lchild, *rchild, *parent;
} BiTreeNode, BiTree; 

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

//先序遍历二叉树
Status preOrderTraverse(BiTree *t, Status (*visit)(BiTreeNode *t)) {
	if (t) {
		if (visit(t)) {
			if (preOrderTraverse(t->lchild, visit)) {
				if (preOrderTraverse(t->rchild, visit)) {
					return OK; 
				} 
			}
		}
		return ERROR;
	}
	else {
		return OK;
	}
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
	preOrderTraverse(t, visit);
	return 0;
}
