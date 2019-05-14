#include <stdio.h>

/**************************
问题：现在 A 和 B 在打纸牌
开始有两个各有 6 张牌，轮流
打牌到桌面，遇到相同的牌便可
将两张相同的牌之间的牌依次
收回手中，通过程序判断谁能
获胜
解决：通过栈与队列
打牌即使入栈与出队
收牌则是出栈与入队 
**************************/

struct queue {
	//用来存储队列中的数据 
	int data[1000];
	//队列的头指针 
	int head;
	//队列的尾指针 
	int tail;
}; 

struct stack {
	//用来存储栈中的数据 
	int data[8];
	//栈顶指针 
	int top;
}; 

/**
* 初始化队列
* @Param q 要初始化的队列的地址 
*/
void initQueue(struct queue *q) {
	int i;
	(*q).head = 0;
	(*q).tail = 0;
	printf("初始化牌:\n");
	for (i = 0; i < 6; i++) {
		scanf("%d", &((*q).data[(*q).tail]));
		(*q).tail++;
	}
}

/**
* 出牌
* @Param q 要出牌的队列
* @Param s 桌面上的牌
* @Param book 标志桌面已有的牌 
*/ 
void putCard(struct queue *q, struct stack *s, int *book) {
	int tmp, get;
	//将手中的第一张牌取出 
	tmp = (*q).data[(*q).head];
	(*q).head++;
	//桌面上没有这张牌 
	if (book[tmp] == 0) {
		(*s).top++;
		(*s).data[(*s).top] = tmp;
		book[tmp] = 1; 
	} 
	//如果桌面上有这张牌 
	else {
		//将打出的牌收回 
		(*q).data[(*q).tail] = tmp;
		(*q).tail++;
		while ((get = (*s).data[(*s).top]) != tmp) {
			(*q).data[(*q).tail] = get;
			//获取到牌则取消标志 
			book[get] = 0;
			(*q).tail++;
			(*s).top--;
		}
		(*q).data[(*q).tail] = tmp;
		(*q).tail++;
		(*s).top--;
		//获取到牌则取消标志
		book[tmp] = 0;
	}
} 

/**
* 打印队列中含有的牌
* @Param q 要打印的队列 
*/
void getQueueCards(struct queue *q) {
	int i;
	for (i = (*q).head; i < (*q).tail; i++) {
		printf("%d ", (*q).data[i]);
	}
} 

/**
* 打印栈中所有的牌 
* @Param s 要打印的栈 
*/
void getStackCards(struct stack *s) {
	int top;
	top = (*s).top;
	if (top != -1) {
		while (top >= 0) {
			printf("%d ", (*s).data[top]);
			top--;
		}
	}
	printf("\n");
}


int main(void) {
	//qa 和 qb 分别表示 A 和 B 手中的牌 
	struct queue qa, qb;
	//表示桌面的牌 
	struct stack s; 
	//标记桌面上已经有的牌
	int book[10], i; 
	//初始化队列
	initQueue(&qa);
	initQueue(&qb);
	//初始化栈
	s.top = -1;
	//初始化标记
	for (i = 1; i < 10; i++) {
		book[i] = 0;
	} 
	//进行出牌
	//当两个人手中都有牌的时候进行 
	while (qa.head < qa.tail && qb.head < qb.tail) {
		putCard(&qa, &s, book);
		if (qa.head == qa.tail) {
			break;
		}
		putCard(&qb, &s, book);
	} 
	//A 手中没牌了 
	if (qa.head == qa.tail) {
		printf("B win\n");
		//打印 B 有的牌 
		printf("B have:");
		getQueueCards(&qb); 
		//打印桌面上有的牌 
		printf("\nDesktop have:");
		getStackCards(&s);
	} 
	//B 手中没牌了
	else {
		printf("A win\n");
		//打印 B 有的牌 
		printf("A have:");
		getQueueCards(&qa); 
		//打印桌面上有的牌 
		printf("\nDesktop have:");
		getStackCards(&s);
	}
	 
	return 0;
}
