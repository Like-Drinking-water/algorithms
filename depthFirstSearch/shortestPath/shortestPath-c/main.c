#include <stdio.h>
#include <stdlib.h>

/*******************************************************
问题：找到最短路径，用二维数组保存图中节点的关系。-1 表示无法
到达;0 表示距离为 0;其他表示到达该点的距离 
解决：深度优先算法 
********************************************************/
//最短路径的长度 
int min = 2147483647; 
//图以及走过的标记
int **graph, *book; 
//图的节点个数以及边数
int n, m; 
//保存路径 
int *path, *shortestPath;
int top = 0, stop = 0;

void dfs(int start, int length) {
	int i;
	path[top] = start;
	top++;
	//如果到达终点且距离比现在最短距离更短
	if (start == 4 && length < min) {
		//获取当前最短距离 
		min = length;
		//保存最短路径 
		for (i = 0; i < top; i++) {
			shortestPath[i] = path[i];
		}
		stop = top;
		return;
	}
	else {
		return;
	}
	for (i = 0; i < n; i++) {
		if (graph[start][i] > 0 && book[i] == 0) {
			book[i] = 1;
			dfs(i, length + graph[start][i]);
			book[i] = 0;
			top--;
		}
	}
	return;
} 

int main(void) {
	//辅助变量以及临时存储变量
	int i, j, a, b, c;
	//输入节点的数量以及边数 
	scanf("%d %d", &n, &m); 
	//给图创建空间 
	graph = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++) {
		graph[i] = (int *)malloc(sizeof(int) * n);
	}
	//给标记创建空间
	book = (int *)malloc(sizeof(int) * n);
	//获取节点关系
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			//两个相同的点的距离为0 
			if (i == j) {
				graph[i][j] = 0;
			}
			//其他点初始化为 -1 
			else {
				graph[i][j] = -1;
			}
		}
	}
	//获取可以到达的点 
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
		graph[a][b] = c;
	} 
	//初始化标记
	for (i = 0; i < n; i++) {
		book[i] = 0;
	}
	//初始化路径
	path = (int *)malloc(sizeof(int) * n);
	shortestPath = (int *)malloc(sizeof(int) * n);
	book[0] = 1;
	//从 0 开始寻找最短路径 
	dfs(0, 0); 
	//打印最短路径以及距离 
	for (i = 0; i < stop - 1; i++) {
		printf("%d -> ", shortestPath[i]);
	} 
	printf("4    length = %d", min);
	return 0;
}
