#include <stdio.h>
#include <string.h> 

/*****************************
问题：检测一个字符串是不是回文
解决：通过栈来解决 
******************************/
struct stack {
	//存放栈中的数据 
	char data[100];
	//栈顶指针 
	int top;
};


int main(void) {
	struct stack s;
	//存放要检测的字符串 
	char a[100];
	int len, mid, i, next;
	//初始化栈
	s.top = -1; 
	//获取字符串 
	gets(a);
	//获取字符串的长度 
	len = strlen(a); 
	//获取字符串的中心下标
	mid = len >> 1;
	//将字符串的前半段存放到栈中 
	for (i = 0; i < mid; i++) {
		s.top++;
		s.data[s.top] = a[i];
	}
	//如果字符串的长度为偶数 
	if (len % 2 == 0) {
		next = mid;
	}
	//如果字符串的长度为奇数 
	else {
		next = mid + 1;
	}
	for (i = next; i < len; i++) {
		if (a[i] != s.data[s.top]) {
			break;
		}
		s.top--;
	} 
	//如果 s.top == -1，说明栈内的值已经进行一一匹配 
	if (s.top == -1) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	
	return 0;
}
