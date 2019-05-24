#include <stdio.h>
#include <stdlib.h>

/*******************************************************
问题：图的遍历，用二维数组保存图中节点的关系。-1 表示无法
到达;0 表示距离为 0;1 表示可以到达
解决：深度优先算法 
********************************************************/
//节点的数量以及边数 
int n, m; 
/**
* 深度优先算法
* @Param start 开始搜索的节点
* @Param graph 保存节点关系的数组
* @Param book 标志路径是否走过 
*/
void dfs(int start, int **graph, int *book) {
	int j;
	printf("到达 %d 号节点\n", start);
	book[start] = 1; 
	//尝试进入其他点 
	for (j = 0; j < n; j++) {
		//能够到达并且还未去过 
		if (graph[start][j] == 1 && !book[j]) {
			dfs(j, graph, book); 
		}
	}
	return; 
} 

int main(int argc, char *argv[]) {
	//临时存储
	int a, b; 
	//辅助变量
	int i, j; 
	//保存节点关系以及走过的标志 
	int **graph, *book;
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
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[a][b] = 1;
	} 
	//初始化标记
	for (i = 0; i < n; i++) {
		book[i] = 0;
	} 
	//进行深度优先搜索
	dfs(0, graph, book); 
	return 0;
}
