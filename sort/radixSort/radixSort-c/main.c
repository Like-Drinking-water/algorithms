#include <stdio.h>
#include <stdlib.h>

/* �������� */
#define MAX_SIZE 20
#define MAX_NUM_OF_KEY 8
#define RADIX 10

typedef int KeyType;
typedef int InfoType;

//��̬�������ݽṹ 
typedef struct {
	KeyType key[MAX_NUM_OF_KEY];
	InfoType info;
	int next;
} SLCell;

typedef struct {
	SLCell r[MAX_SIZE + 1];
	//�ؼ��ָ��� 
	int keynum;
	//���ݸ��� 
	int length; 
} SLList;

void initSLList(SLList *L, int keynum) {
	L->length = 0;
	L->keynum = 2;
}

int SLListInsert(SLList *L, KeyType key, InfoType info) {
	int i;
	for (i = L->keynum - 1; i >= 0; i--) {
		L->r[L->length + 1].key[i] = key % RADIX;
		key /= RADIX;
	}
	L->r[L->length + 1].info = info;
	L->length++; 
}

//���� 
//���ݵ� i ���ؼ��ֽ��з��� 
void distribute(SLCell r[], int i, int f[], int e[]) {
	int j, k;
	//��ʼ������ f 
	for (j = 0; j < RADIX; j++) {
		f[j] = 0;
	}
	for (j = r[0].next; j; j = r[j].next) {
		k = r[j].key[i];
		//f[k] Ϊ�� 
		if (!f[k]) {
			f[k] = j;
		}
		else {
			r[e[k]].next = j;
		}
		e[k] = j;
	}
}

//�ռ� 
void collect(SLCell r[], int i, int f[], int e[]) {
	int j, t;
	//�����ҵ���һ����Ϊ�յ� f[j] 
	for (j = 0; j < RADIX - 1 && !f[j]; j++);
	r[0].next = f[j];
	t = e[j];
	while (j < RADIX) {
		//����Ѱ����һ���ǿյ� f[j] 
		for (j++; j < RADIX - 1 && !f[j]; j++);
		if (j < RADIX && f[j]) {
			r[t].next = f[j];
			t = e[j];
		}
	}
	r[t].next = 0;
}

void radixSort(SLList *L) {
	int i;
	int f[RADIX], e[RADIX];
	for (i = 0; i < L->length; i++) {
		L->r[i].next = i + 1;
	}
	L->r[i].next = 0;
	//�� n ���ؼ��ֽ��з������ռ�
	//��ɻ����������Ҫ���� 
	for (i = L->keynum - 1; i >= 0; i--) {
		distribute(L->r, i, f, e);
		collect(L->r, i, f, e);
	}
}

int main(int argc, char *argv[]) {
	SLList L;
	int i, j;
	initSLList(&L, 2);
	SLListInsert(&L, 11, 0);
	SLListInsert(&L, 1, 0);
	SLListInsert(&L, 31, 0);
	SLListInsert(&L, 44, 0);
	SLListInsert(&L, 22, 0);
	SLListInsert(&L, 33, 0);
	radixSort(&L);
	for (i = L.r[0].next; i; i = L.r[i].next) {
		for (j = 0; j < L.keynum; j++) {
			printf("%d", L.r[i].key[j]);
		}
		printf(" ");
	}
	return 0;
}
