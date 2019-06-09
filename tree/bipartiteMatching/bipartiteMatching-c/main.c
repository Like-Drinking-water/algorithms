#include <stdio.h>
#include <stdlib.h>

/********************************************
问题：二分图匹配 
********************************************/
//记录配对 
int match[20];
//图 
int graph[20][20];
//边数以及顶点个数
int n, m; 
//标记是否已经经过
int book[20];

int dfs(int u) {
	int i;
	for (i = 0; i < n; i++) {
		if (book[i] == 0 && graph[u][i] == 1) {
			//标记已经来过 
			book[i] = 1;
			if (match[i] == -1 || dfs(match[i]) == 1) {
				//更新配对关系
				match[i] = u;
				match[u] = i;
				return 1; 
			} 
		}
	}
	return 0;
} 

int main(void) {
	int i, j;
	int x, y;
	//记录配对总数 
	int sum = 0; 
	//获取图的大小
	scanf("%d %d", &n, &m);
	//读取图
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	} 
	
	for (i = 0; i < n; i++) {
		match[i] = -1;
	}
	for (i = 0; i < n; i++) {
		//清空标记 
		for (j = 0; j < n; j++) {
			book[j] = 0;
		}
		if (dfs(i)) {
			sum++;
		} 
	}
	printf("%d", sum);
	return 0;
}
