#include <stdio.h>
#include <stdlib.h>

/***************************************************
问题：单源最短路径 
解决：使用 Dijkstra 算法 
***************************************************/

int main(void) {
	//图 
	int **graph;
	int *dis;
	int min;
	//路径
	int **path;
	int last = 0;
	//最大 int 值 认为是无穷值 
	int inf = 214783647;
	//标记是否已知最短路径
	int *book;
	//节点数和边数
	int n, m;
	//辅助变量和临时存储变量
	int i, j, u, v, a, b, c;
	//单源最短路径的起点 
	int s;
	//获取节点的数量以及边数还有起点 
	scanf("%d %d %d", &n, &m, &s); 
	//给图创建空间 
	graph = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++) {
		graph[i] = (int *)malloc(sizeof(int) * n);
	}
	//给路径分配空间 
	path = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++) {
		path[i] = (int *)malloc(sizeof(int) * n);
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
	//初始化标志
	book = (int *)malloc(sizeof(int) * n);
	//初始化源点距离
	dis = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		dis[i] = graph[s][i];
	} 
	//标记初始化
	for (i = 0; i < n; i++) {
		book[i] = 0;
	} 
	//源点到源点已经到达最短路径 
	book[s] = 1;
	//初始化路径 
	for (i = 0; i < n; i++) {
		path[i][0] = s;
	}
	last++;
	//Dijstra 算法核心代码 
	for (i = 0; i < n - 1; i++) {
		min = inf;
		//找到离源点最近的点 
		for (j = 0; j < n; j++) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		} 
		book[u] = 1;
		if (last == 1) {
			path[u][last] = u;
		}
		last++;
		for (v = 0; v < n; v++) {
			//表示能够到达 
			if (graph[u][v] < inf) {
				if (book[v] == 0 && dis[v] > min + graph[u][v]) {
					dis[v] = min + graph[u][v];
					//合成路径 
					for (j = 0; j < last; j++) {
						path[v][j] = path[u][j];
					}
					path[v][last] = v;
				} 	
			}
		}
	}
	//输出结果
	for (i = 0; i < n; i++) {
		printf("%d ", dis[i]);
	} 
	printf("\n");
	//输出路径
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == path[i][j]) {
				printf("%d\n", i);
				break;
			} 
			printf("%d -> ", path[i][j]);
		} 
	} 
	return 0;
}
