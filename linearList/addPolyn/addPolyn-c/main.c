#include <stdio.h>
#include <stdlib.h>

/***********************************************
问题：多项式相加
解决：使用结构体来保存系数与指数 再用链表将结构体
联系起来 
************************************************/
#define OVERFLOW -2

typedef struct {
	float coef; //系数
	int expn; //指数 
} Elem; 

typedef struct LNode {
	Elem data;
	struct LNode *next;
} LNode, LinkList;

typedef LinkList Polynomial;

//比较两个指数大小 
int cmp(Elem a, Elem b) {
	if (a.expn < b.expn) {
		return -1; 
	}
	else if (a.expn > b.expn) {
		return 1;
	}
	else {
		return 0;
	}
}

LNode *makeNode(Elem e) {
	LNode *node;
	node = (LNode *)malloc(sizeof(LNode));
	if (!node) {
		//分配内存空间失败 
		exit(OVERFLOW);
	} 
	node->data = e;
	node->next = NULL;
	return node;
}

int isExist(Polynomial *P, Elem e) {
	LNode *node;
	node = P->next;
	while (node) {
		//表示存在 
		if (!cmp(node->data, e)) {
			return 1;
		}
		node = node->next;
	} 
	//表示不存在 
	return 0;
}

//创建一个m项式 
Polynomial *createPolyn(int m) {
	Elem e;
	int i;
	Polynomial *P;
	LNode *p, *q;
	P = (Polynomial *)malloc(sizeof(Polynomial));
	if (!P) {
		//分配内存空间失败 
		exit(OVERFLOW);
	} 
	P->next = NULL;
	for (i = 0; i < m; i++) {
		scanf("%f %d", &e.coef, &e.expn);
		//如果不存在该指数项 
		if (!isExist(P, e)) {
			p = makeNode(e);
			if (i == 0) {
				P->next = p;
				q = p;
			}
			else {
				q->next = p;
				q = p;
			}
		}
	}
	return P;
	
}

void AddPolyn(Polynomial *Pa, Polynomial *Pb) {
	Elem a, b;
	float sum;
	LNode *p, *q, *ha, *hb;
	p = Pa->next;
	ha = (LNode *)Pa;
	q = Pb->next;
	hb = (LNode *)Pb;
	while (p && q) {
		a = p->data;
		b = q->data;
		switch (cmp(a, b)) {
			case -1:
				ha = p;
				p = p->next;
				break;
			case 0:
				//系数相加 
				sum = a.coef + b.coef;
				//相加后不等于0
				if (sum != 0.0) {
					p->data.coef = sum;
				} 
				//等于0则将该结点删除
				else {
					ha->next = p->next;
					free(p);
				}
				hb->next = q->next;
				free(q);
				p = ha->next;
				q = hb->next;
				break;
			case 1:
				ha->next = q;
				hb->next = q->next;
				q->next = p;
				ha = q;
				q = hb->next;
				break;
		}
	}
	if (hb->next) {
		ha->next = hb->next;
	}
	free(hb);
}

int main(void) {
	Polynomial *Pa, *Pb;
	LNode *p;
	//创建多项式 
	Pa = createPolyn(4);
	printf("------------------------\n"); 
	Pb = createPolyn(5);
	//多项式相加
	AddPolyn(Pa, Pb);
	p = Pa->next;
	while (p != NULL) {
		printf("%f %d\n", p->data.coef, p->data.expn);
		p = p->next;
	}
	 
	return 0;
}
