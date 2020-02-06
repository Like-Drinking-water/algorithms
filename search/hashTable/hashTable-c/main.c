#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 36
#define NULL_KEY -9999
#define OK 1
#define OVERFLOW -1 
#define ERROR 0;

typedef int ElemType;
typedef struct {
	//保存散列表的基址 
	ElemType *elem;
	//记录散列表中保存的数据个数 
	int count;
}HashTable;

//初始化散列表 
int initHashTable(HashTable *t) {
	int i;
	t->elem = (ElemType *)malloc(sizeof(ElemType) * TABLE_SIZE);
	if (!t->elem) {
		exit(OVERFLOW);
	}
	t->count = 0;
	for (i = 0; i < TABLE_SIZE; i++) {
		t->elem[i] = NULL_KEY;
	}
	return OK;
}

//散列函数 
int Hash(ElemType k) {
	return (k % TABLE_SIZE);
} 

//添加数据 
int insert(HashTable *t, ElemType e) {
	int addr;
	if (!t || t->count == TABLE_SIZE) {
		return ERROR;
	}
	addr = Hash(e);
	//当出现冲突时 
	while (t->elem[addr] != NULL_KEY) {
		addr = (addr + 1) % TABLE_SIZE;
	}
	t->elem[addr] = e;
	t->count++;
	return OK; 
}

int search(HashTable *t, ElemType e) {
	int addr;
	addr = Hash(e);
	while (t->elem[addr] != e) {
		addr = (addr + 1) % TABLE_SIZE;
		if (t->elem[addr] == NULL_KEY || addr == Hash(e)) {
			return -1;
		} 
	}
	return addr;
}


int main(int argc, char *argv[]) {
	int addr;
	HashTable t;
	initHashTable(&t);
	insert(&t, 44);
	insert(&t, 6);
	addr = search(&t, 44);
	printf("%d", addr);
	return 0;
}
