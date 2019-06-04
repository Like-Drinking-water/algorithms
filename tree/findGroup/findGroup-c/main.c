#include <stdio.h>
#include <stdlib.h>

/**************************************************
问题：通过两两的关系判断其中有多少组 
***************************************************/
//存放人与组的关系 
int f[100] = {0};
//多少个人以及多少组关系 
int n, m;

/**
* 初始化人和组的关系 
*/
void init() {
	int i;
	for (i = 0; i < n; i++) {
		f[i] = i;
	}
} 

/**
* 找到组长
* @param i 第几个人 
*/
int getFather(int i) {
	if (i == f[i]) {
		return i; 
	} 
	else {
		//将所有点都指向一个父节点 
		f[i] = getFather(f[i]);
		return f[i];
	}
} 

/**
* 合并两组人  
*/
void merge(int i, int j) {
	int t1, t2;
	t1 = getFather(i);
	t2 = getFather(j);
	//两个人不同组 
	if (t1 != t2) {
		f[t2] = t1;
	}
}

int main(void) {
	int i, x, y;
	//统计一共有多少组 
	int sum = 0; 
	//获取有多人个人以及多少组关系 
	scanf("%d %d", &n, &m);
	//初始化 
	init(); 
	//获取关系并合并组 
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		merge(x, y);
	} 
	//获取多少组 
	for (i = 0; i < n; i++) {
		if (i == f[i]) {
			sum++; 
		}
	}
	//打印结果 
	printf("%d", sum);
	return 0;
}
