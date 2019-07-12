#include <stdio.h>
#include <stdlib.h>

/**************************************
问题：字符串匹配 
***************************************/

#define MAXSTRLEN 255

typedef unsigned char SString[MAXSTRLEN + 1];

int next[MAXSTRLEN + 1];

//获取next 
//void getNext(SString s, int next[]) {
//	int i, j;
//	i = 1;
//	j = 0;
//	next[1] = 0;
//	while (i < s[0]) {
//		if (j == 0 || s[i] == s[j]) {
//			i++;
//			j++;
//			next[i] = j;
//		}
//		else {
//			j = next[j]; 
//		}
//	}
//}
void getNext(SString s, int next[]) {
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < s[0]) {
		if (j == 0 || s[i] == s[j]) {
			i++;
			j++;
			if (s[i] != s[j]) {
				next[i] = j;
			} 
			else {
				next[i] = next[j];
			}
		}
		else {
			j = next[j];
		}
	}
}

//匹配失败返回 -1； 匹配到返回开始匹配位置 
int Index(SString s, SString t, int pos) {
	int i, j;
	i = pos;
	j = 1;
	getNext(t, next);
	while (i <= s[0] && j <= t[0]) {
		if (j == 0 || s[i] == t[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j > t[0]) {
		return i - t[0];
	}
	else {
		return -1;
	}
}

int main(void) {
	SString s, t;
	s[0] = 7; s[1] = '1'; s[2] = '0'; s[3] = '0'; s[4] = '0'; s[5] = '0'; s[6] = '1'; s[7] = '1';
	t[0] = 3; t[1] = '0'; t[2] = '1'; t[3] = '1';
	printf("%d", Index(s, t, 1));
	return 0;
}
