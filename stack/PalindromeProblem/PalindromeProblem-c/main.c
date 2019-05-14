#include <stdio.h>
#include <string.h> 

/*****************************
���⣺���һ���ַ����ǲ��ǻ���
�����ͨ��ջ����� 
******************************/
struct stack {
	//���ջ�е����� 
	char data[100];
	//ջ��ָ�� 
	int top;
};


int main(void) {
	struct stack s;
	//���Ҫ�����ַ��� 
	char a[100];
	int len, mid, i, next;
	//��ʼ��ջ
	s.top = -1; 
	//��ȡ�ַ��� 
	gets(a);
	//��ȡ�ַ����ĳ��� 
	len = strlen(a); 
	//��ȡ�ַ����������±�
	mid = len >> 1;
	//���ַ�����ǰ��δ�ŵ�ջ�� 
	for (i = 0; i < mid; i++) {
		s.top++;
		s.data[s.top] = a[i];
	}
	//����ַ����ĳ���Ϊż�� 
	if (len % 2 == 0) {
		next = mid;
	}
	//����ַ����ĳ���Ϊ���� 
	else {
		next = mid + 1;
	}
	for (i = next; i < len; i++) {
		if (a[i] != s.data[s.top]) {
			break;
		}
		s.top--;
	} 
	//��� s.top == -1��˵��ջ�ڵ�ֵ�Ѿ�����һһƥ�� 
	if (s.top == -1) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	
	return 0;
}
