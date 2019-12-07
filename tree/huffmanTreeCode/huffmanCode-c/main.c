#include <stdio.h>
#include <stdlib.h>

/* 赫夫曼编码 */

typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, * HuffmanTree;
typedef char** HuffmanCode;

void select(HuffmanTree HT, int index, int *s1, int *s2) {
	int min1[2], min2[2];
	int i;
	min1[0] = 99999;
	min2[0] = 99999;
	min1[1] = 0;
	min2[1] = 0;
	for (i = 1; i <= index; i++) {
		if (HT[i].parent == 0) {
			if (HT[i].weight < min1[0]) {
				if (HT[i].weight < min2[0]) {
					min1[0] = min2[0];
					min1[1] = min2[1];
					min2[0] = HT[i].weight;
					min2[1] = i;	
				}
				else {
					min1[0] = HT[i].weight;
					min1[1] = i;
				}
			}
		}
	}
	*s1 = min1[1];
	*s2 = min2[1];
}

void strcpy1(char *str1, char *str2) {
	char c;
	int i = 0;
	c = *str2;
	while (c != '\0') {
		str1[i] = c;
		i++;
		c = str2[i];
	}
	str1[i] = c;
}

void HuffmanCoding(HuffmanCode HC, int *w, int n) {
	HuffmanTree HT;
	HuffmanTree p;
	int i, s1, s2, c, f, start, cdlen, j;
	int m;
	char *cd;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	for (p = HT + 1, i = 1; i <= n; i++, p++, w++) {
		p->weight = *w;
		p->lchild = 0;
		p->rchild = 0;
		p->parent = 0;
	}
	for (; i <= m; i++, p++) {
		p->weight = 0;
		p->lchild = 0;
		p->rchild = 0;
		p->parent = 0;
	}
	for (i = n + 1; i <= m; i++) {
		//从HT[1...i-1]找到parent为0且权最小的两个结点 
		select(HT, i - 1, &s1, &s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	cd = (char *)malloc(n * sizeof(char));
//	cd[n - 1] = '\0';
//	for (i = 1; i <= n; i++) {
//		start = n - 1;
//		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) {
//			if (HT[f].lchild == c) {
//				start--;
//				cd[start] = '0';
//			}
//			else {
//				start--;
//				cd[start] = '1';
//			}
//		}
//		strcpy1(HC[i], &cd[start]);
//	}
	//根结点的位置 
	j = m;
	cdlen = 0;
	for (i = 1; i <= m; i++) {
		HT[i].weight = 0;
	}
	while (j) {
		if (HT[j].weight == 0) { //向左 
			HT[j].weight = 1;
			if (HT[j].lchild != 0) {
				j = HT[j].lchild;
				cd[cdlen] = '0';
				cdlen++;
			} 
			else if (HT[j].rchild == 0) {
				cd[cdlen] = '\0';
				HC[j] = (char *)malloc((cdlen + 1) * sizeof(char));
				strcpy1(HC[j], cd);
			}
		}
		else if (HT[j].weight == 1) {
			HT[j].weight = 2;
			if (HT[j].rchild != 0) {
				j = HT[j].rchild;
				cd[cdlen] = '1';
				cdlen++;
			}
		}
		else {
			HT[j].weight = 0;
			j = HT[j].parent;
			cdlen--;
		}
	}
	free(cd);
	free(HT);
} 

int main(int argc, char *argv[]) {
	HuffmanCode HC;
	int *w;
	int n;
	int i;
	scanf("%d", &n);
	w = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
//	for (i = 1; i <= n; i++) {
//		HC[i] = (char *)malloc(n * sizeof(char));
//	}
	HuffmanCoding(HC, w, n);
	for (i = 1; i <= n; i++) {
		printf("%s\n", HC[i]);
	}
	return 0;
}
