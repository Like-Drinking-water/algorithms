#include <stdio.h>
#include <stdlib.h>

/***************************************************
问题：找到图中两节点的最短路径
解决：使用 Floyd-Warshall 算法 
***************************************************/

int main() {
	//最大 int 值 认为是无穷值 
	int inf = 214783647;
	//图中节点的数量以及边数
	int n, m;
	//辅助变量以及临时存储变量
	int i, j, k, a, b, c; 
	//图 
	int **graph;
	//获取节点的数量以及边数
	scanf("%d %d", &n, &m); 
	//给图创建空间 
	graph = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++) {
		graph[i] = (int *)malloc(sizeof(int) * n);
	}
	//获取节点关系
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			//两个相同的点的距离为0 
			if (i == j) {
				graph[i][j] = 0;
			}
			//其他点初始化为 -1 
			else {
				graph[i][j] = inf;
			}
		}
	}
	//获取可以到达的点 
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
	}
	// Floyd-Warshall 算法核心语句
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (graph[i][k] < inf && graph[k][j] < inf && graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	} 
	//打印结果
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%2d", graph[i][j]);
		}
		printf("\n");
	} 
	return 0;
}
