#include <stdio.h>
#include <stdlib.h>

/**********************************************
************* ������������һ���� ************ 
***********************************************/

typedef struct node {
	int data;
	struct node *next;
} Node; 

int main() {
	Node *head, *p, *q, *next;
	int n, i, a;
	//ͷָ���ʼΪ�� 
	head = NULL;
	//��ȡҪ��ȡ������ 
	scanf("%d", &n);
	//��ȡ 
	for (i = 0; i < n; i++) {
		//��ȡһ���� 
		scanf("%d", &a);
		//���ڵ�����ڴ�ռ� 
		p = (Node *)malloc(sizeof(Node));
		p->data = a;
		p->next = NULL;
		//���ͷָ���ǿյģ��򽫽ڵ��ַ��ͷָ�� 
		if (head == NULL) {
			head = p;  
		}
		//�ǿգ�����һ�ڵ����ָ��ָ���½ڵ� 
		else {
			q->next = p; 
		}
		q = p;
	}
	//����һ����
	scanf("%d", &a);
	next = head;
	p = (Node *)malloc(sizeof(Node));
	p->data = a;
	//�������ӵ����ݱ�ͷ�ڵ������С
	//��ͷ�ڵ�Ϊ��
	//���½ڵ���Ϊͷ�ڵ� 
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
	
	
	
	//�������
	next = head;
	while (next != NULL) {
		printf("%d ", next->data);
		next = next->next;
	} 
	return 0;
}
