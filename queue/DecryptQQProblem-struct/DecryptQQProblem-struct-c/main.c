#include <stdio.h>
#include <stdlib.h>

/******************************************** 
问题：解密 qq 号, 解密方法将现有 qq 号
的第一个数删除，将第二位移到最后一位
循环操作，直到只剩最后一位，将最后一位也删除，
删除的顺序便是 qq 号  
解决：通过队列 
*********************************************/ 

struct queue {
	//队列的数据载体 
	int data[20];
	//队列中的头指针 
	int head;
	//队列中的尾指针 
	int tail;
}; 

int main(void) {
	struct queue q;
	int i;
	//初始化队列 
	q.head = 0;
	q.tail = 0;
	for (i = 0; i < 9; i++) {
		scanf("%d", &q.data[i]);
		q.tail++;
	}
	//进行解密
	while (q.head < q.tail) {
		//将要删除的数进行输出 
		printf("%d", q.data[q.head]);
		q.head++;
		//将第二个数放到队列的最后
		q.data[q.tail] = q.data[q.head];
		q.tail++;
		q.head++; 
	}  
	return 0;
}
