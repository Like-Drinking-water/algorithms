#include <stdio.h>
#include <stdlib.h>

/**************************************
ÎÊÌâ£º×Ö·û´®Æ¥Åä 
***************************************/

#define MAXSTRLEN 255
#define ERROR -1

typedef unsigned char SString[MAXSTRLEN + 1];

int Index(SString s, SString t, int pos) {
	int i, j;
	i = pos;
	j = 1;
	if (pos < 1 || pos > s[0]) {
		return ERROR;
	}
	while (i <= s[0] && j <= t[0]) {
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 2;
			j = 1;
		}
	}
	if (j = t[0] + 1) {
		return i - j + 1;
	}
	else {
		return -1;
	}
}

int main(void) {
	SString s, t;
	s[0] = 7; s[1] = 'W'; s[2] = 'e'; s[3] = 'l'; s[4] = 'c'; s[5] = 'o'; s[6] = 'm'; s[7] = 'e';
	t[0] = 4; t[1] = 'c'; t[2] = 'o'; t[3] = 'm'; t[4] = 'e';
	printf("%d", Index(s, t, 1));
	return 0;
}
