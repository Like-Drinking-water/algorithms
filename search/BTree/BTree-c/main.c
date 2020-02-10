#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* B�� */
#define M 3
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0 

typedef struct BTNode {
	//�ؼ��ָ��� 
	int keynum;
	//�����
	struct BTNode *parent;
	//�ؼ���
	int key[M + 1]; 
	//���� 
	struct BTNode *ptr[M + 1];
} BTNode, *BTree;

typedef struct {
	BTNode *ptr;
	//����е���� 
	int i;
	//1 ��ʾ���ҳɹ�
	//0 ��ʾ����ʧ�� 
	int tag;
} Result;

//ͨ�� key �ڽ�����ҵ���Ӧ key ���±���������±� 
int search(BTNode *p, int key) {
	int i;
	for (i = 1; i <= p->keynum; i++) {
		if (p->key[i] > key) {
			break;
		}
	}
	return (i - 1);
} 

Result searchBTree(BTree T, int key) {
	BTNode *p, *q;
	Result r;
	int found = FALSE;
	int i = 0;
	p = T;
	q = NULL;
	while (p && !found) {
		i = search(p, key);
		//���ص� i ���ڽ���ϵ���� 
		if (i > 0 && p->key[i] == key) {
			found = TRUE;
		}
		else {
			q = p;
			p = p->ptr[i];
		}
	}
	//�ҵ��� 
	if (found) {
		r.ptr = p;
		r.i = i;
		r.tag = 1;
	}
	//û���ҵ� 
	else {
		r.ptr = q;
		r.i = i;
		r.tag = 0;
	}
	return r;
}

void insert(BTNode *q, int i, int key, BTNode *ap) {
	int j;
	//����� 
	for (j = q->keynum; j > i; j--) {
		q->key[j + 1] = q->key[j]; 
		q->ptr[j + 1] = q->ptr[j];
	}
	q->key[i + 1] = key;
	q->ptr[i + 1] = ap;
	ap->parent = q; 
	q->keynum++;
} 

void split(BTNode *q, int s, BTNode *ap) {
	int i, j;
	q->keynum = s - 1;
	for (i = 1, j = s + 1; j <= M; i++, j++) {
		ap->key[i] = q->key[j];
		ap->ptr[i] = q->ptr[j];
	}
	ap->ptr[0] = q->ptr[s];
	ap->keynum = M - s;
}

void NewRoot(BTree *T, BTNode *q, int key, BTNode *ap) {
	*T = (BTree)malloc(sizeof(BTNode));
	(*T)->ptr[0] = q;
	q->parent = *T;
	(*T)->key[1] = key;
	(*T)->ptr[1] = ap;
	ap->parent = *T;
	(*T)->parent = NULL;
}

int insertBTree(BTree *T, int key) {
	BTNode *ap, *q;
	int finished = FALSE;
	int s;
	int x = key;
	int i;
	Result r;
	r = searchBTree(*T, key);
	//B �����Ѿ����� ������� 
	if (r.tag) {
		return ERROR; 
	}
	q = r.ptr;
	ap = NULL;
	i = r.i;
	while (q && !finished) {
		insert(q, i, x, ap);
		if (q->keynum < M) {
			finished = TRUE;
		}
		else {
			s = ceil(M / 2.0);
			ap = (BTNode *)malloc(sizeof(BTNode));
			split(q, s, ap);
			x = q->key[s];
			q = q->parent; 
			if (q) {
				i = search(q, x);
			}
		}
	}
	if (!finished) {
		NewRoot(T, q, x, ap);
	} 
	return OK;
}

int main(int argc, char *argv[]) {
	
	return 0;
}
