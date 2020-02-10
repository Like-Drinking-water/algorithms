#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* B树 */
#define M 3
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0 

typedef struct BTNode {
	//关键字个数 
	int keynum;
	//父结点
	struct BTNode *parent;
	//关键字
	int key[M + 1]; 
	//子树 
	struct BTNode *ptr[M + 1];
} BTNode, *BTree;

typedef struct {
	BTNode *ptr;
	//结点中的序号 
	int i;
	//1 表示查找成功
	//0 表示查找失败 
	int tag;
} Result;

//通过 key 在结点中找到对应 key 的下标或者子树下标 
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
		//返回的 i 是在结点上的序号 
		if (i > 0 && p->key[i] == key) {
			found = TRUE;
		}
		else {
			q = p;
			p = p->ptr[i];
		}
	}
	//找到了 
	if (found) {
		r.ptr = p;
		r.i = i;
		r.tag = 1;
	}
	//没有找到 
	else {
		r.ptr = q;
		r.i = i;
		r.tag = 0;
	}
	return r;
}

void insert(BTNode *q, int i, int key, BTNode *ap) {
	int j;
	//向后移 
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
	//B 树中已经存在 无需添加 
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
