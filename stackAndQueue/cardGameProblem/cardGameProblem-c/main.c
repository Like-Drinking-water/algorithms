#include <stdio.h>

/**************************
���⣺���� A �� B �ڴ�ֽ��
��ʼ���������� 6 ���ƣ�����
���Ƶ����棬������ͬ���Ʊ��
��������ͬ����֮���������
�ջ����У�ͨ�������ж�˭��
��ʤ
�����ͨ��ջ�����
���Ƽ�ʹ��ջ�����
�������ǳ�ջ����� 
**************************/

struct queue {
	//�����洢�����е����� 
	int data[1000];
	//���е�ͷָ�� 
	int head;
	//���е�βָ�� 
	int tail;
}; 

struct stack {
	//�����洢ջ�е����� 
	int data[8];
	//ջ��ָ�� 
	int top;
}; 

/**
* ��ʼ������
* @Param q Ҫ��ʼ���Ķ��еĵ�ַ 
*/
void initQueue(struct queue *q) {
	int i;
	(*q).head = 0;
	(*q).tail = 0;
	printf("��ʼ����:\n");
	for (i = 0; i < 6; i++) {
		scanf("%d", &((*q).data[(*q).tail]));
		(*q).tail++;
	}
}

/**
* ����
* @Param q Ҫ���ƵĶ���
* @Param s �����ϵ���
* @Param book ��־�������е��� 
*/ 
void putCard(struct queue *q, struct stack *s, int *book) {
	int tmp, get;
	//�����еĵ�һ����ȡ�� 
	tmp = (*q).data[(*q).head];
	(*q).head++;
	//������û�������� 
	if (book[tmp] == 0) {
		(*s).top++;
		(*s).data[(*s).top] = tmp;
		book[tmp] = 1; 
	} 
	//����������������� 
	else {
		//����������ջ� 
		(*q).data[(*q).tail] = tmp;
		(*q).tail++;
		while ((get = (*s).data[(*s).top]) != tmp) {
			(*q).data[(*q).tail] = get;
			//��ȡ������ȡ����־ 
			book[get] = 0;
			(*q).tail++;
			(*s).top--;
		}
		(*q).data[(*q).tail] = tmp;
		(*q).tail++;
		(*s).top--;
		//��ȡ������ȡ����־
		book[tmp] = 0;
	}
} 

/**
* ��ӡ�����к��е���
* @Param q Ҫ��ӡ�Ķ��� 
*/
void getQueueCards(struct queue *q) {
	int i;
	for (i = (*q).head; i < (*q).tail; i++) {
		printf("%d ", (*q).data[i]);
	}
} 

/**
* ��ӡջ�����е��� 
* @Param s Ҫ��ӡ��ջ 
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
	//qa �� qb �ֱ��ʾ A �� B ���е��� 
	struct queue qa, qb;
	//��ʾ������� 
	struct stack s; 
	//����������Ѿ��е���
	int book[10], i; 
	//��ʼ������
	initQueue(&qa);
	initQueue(&qb);
	//��ʼ��ջ
	s.top = -1;
	//��ʼ�����
	for (i = 1; i < 10; i++) {
		book[i] = 0;
	} 
	//���г���
	//�����������ж����Ƶ�ʱ����� 
	while (qa.head < qa.tail && qb.head < qb.tail) {
		putCard(&qa, &s, book);
		if (qa.head == qa.tail) {
			break;
		}
		putCard(&qb, &s, book);
	} 
	//A ����û���� 
	if (qa.head == qa.tail) {
		printf("B win\n");
		//��ӡ B �е��� 
		printf("B have:");
		getQueueCards(&qb); 
		//��ӡ�������е��� 
		printf("\nDesktop have:");
		getStackCards(&s);
	} 
	//B ����û����
	else {
		printf("A win\n");
		//��ӡ B �е��� 
		printf("A have:");
		getQueueCards(&qa); 
		//��ӡ�������е��� 
		printf("\nDesktop have:");
		getStackCards(&s);
	}
	 
	return 0;
}
