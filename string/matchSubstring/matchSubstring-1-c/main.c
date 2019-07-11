#include <stdio.h>
#include <stdlib.h>

/*********************************
问题：匹配子串 
*********************************/

#define String char *
#define ERROR 0
#define OK 1
#define Status int

int stringLength(String s) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}

Status subString(String sub, String s, int start, int length) {
	int i;
//	if (start < 0 || length < 0 || length + start > stringLength(s)) {
//		return ERROR;
//	} 
	for (i = 0; i < length; i++) {
		sub[i] = s[start + i];
	}
	sub[i] = '\0';
	return OK;
}

int strCompare(String s, String t) {
	int n, m;
	int i;
	n = stringLength(s);
	m = stringLength(t);
	if (n != m) {
		return n - m;
	}
	else {
		for (i = 0; i < m; i++) {
			if (s[i] != t[i]) {
				break;
			}	
		}
		if (i != m) {
			return -1; 
		}
		else {
			return 0;
		}
	}
}

/**
* 从指定位置开始匹配子串 如果匹配到返回子串下标
* @param s 要找子串的字符串
* @param t 匹配的子串的字符串
* @param pos 开始匹配的位置 
*/
int Index(String s, String t, int pos) {
	//保存 s 和 t 的字符串长度 
	int n, m;
	int i;
	String sub;
	if (pos >= 0) {
		n = stringLength(s);
		m = stringLength(t);
		sub = (String)malloc((m + 1) * sizeof(char));
		i = pos;
		while (n - m - i >= 0) {
			subString(sub, s, i, m);
   			if (strCompare(sub, t)) {
				i++;
			}
			else {
				return i;
			}
		}
	} 
} 

int main(void) {
	String s;
	String t;
	s = "Welcome to China";
	t = "to China";
	printf("%d", Index(s, t, 0));
	return 0;
}
