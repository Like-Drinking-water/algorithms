#include <stdio.h>
#include <stdlib.h>

/***********************************************
���⣺����ʽ���
�����ʹ�ýṹ��������ϵ����ָ�� ���������ṹ��
��ϵ���� 
************************************************/
#define OVERFLOW -2

typedef struct {
	float coef; //ϵ��
	int expn; //ָ�� 
} Elem; 

typedef struct LNode {
	Elem data;
	struct LNode *next;
} LNode, LinkList;

typedef LinkList Polynomial;

//�Ƚ�����ָ����С 
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
		//�����ڴ�ռ�ʧ�� 
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
		//��ʾ���� 
		if (!cmp(node->data, e)) {
			return 1;
		}
		node = node->next;
	} 
	//��ʾ������ 
	return 0;
}

//����һ��m��ʽ 
Polynomial *createPolyn(int m) {
	Elem e;
	int i;
	Polynomial *P;
	LNode *p, *q;
	P = (Polynomial *)malloc(sizeof(Polynomial));
	if (!P) {
		//�����ڴ�ռ�ʧ�� 
		exit(OVERFLOW);
	} 
	P->next = NULL;
	for (i = 0; i < m; i++) {
		scanf("%f %d", &e.coef, &e.expn);
		//��������ڸ�ָ���� 
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
				//ϵ����� 
				sum = a.coef + b.coef;
				//��Ӻ󲻵���0
				if (sum != 0.0) {
					p->data.coef = sum;
				} 
				//����0�򽫸ý��ɾ��
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
	//��������ʽ 
	Pa = createPolyn(4);
	printf("------------------------\n"); 
	Pb = createPolyn(5);
	//����ʽ���
	AddPolyn(Pa, Pb);
	p = Pa->next;
	while (p != NULL) {
		printf("%f %d\n", p->data.coef, p->data.expn);
		p = p->next;
	}
	 
	return 0;
}
