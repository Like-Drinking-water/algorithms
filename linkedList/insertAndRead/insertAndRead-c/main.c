#include <stdio.h>
#include <stdlib.h>

/**********************************************
************* 创建链表并插入一个数 ************ 
***********************************************/

typedef struct node {
	int data;
	struct node *next;
} Node; 

int main() {
	Node *head, *p, *q, *next;
	int n, i, a;
	//头指针初始为空 
	head = NULL;
	//获取要读取多少数 
	scanf("%d", &n);
	//读取 
	for (i = 0; i < n; i++) {
		//获取一个数 
		scanf("%d", &a);
		//给节点分配内存空间 
		p = (Node *)malloc(sizeof(Node));
		p->data = a;
		p->next = NULL;
		//如果头指针是空的，则将节点地址给头指针 
		if (head == NULL) {
			head = p;  
		}
		//非空，则将上一节点的下指针指向新节点 
		else {
			q->next = p; 
		}
		q = p;
	}
	//插入一个数
	scanf("%d", &a);
	next = head;
	p = (Node *)malloc(sizeof(Node));
	p->data = a;
	//如果新添加的数据比头节点的数据小
	//或头节点为空
	//则将新节点作为头节点 
	if (head->data > a || head == NULL) {
		p->next = head;
		head = p;
	} 
	else {
		while (next != NULL) {
			if (next->next == NULL || next->next->data > a) {
				p->next = next->next;
				next->next = p;
				break;
			}
			next = next->next;
		}
	}
	
	
	
	//进行输出
	next = head;
	while (next != NULL) {
		printf("%d ", next->data);
		next = next->next;
	} 
	return 0;
}
