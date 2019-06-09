#include <stdio.h>
#include <stdlib.h>

/*******************************************
获取最小生成树 
*******************************************/ 

int main(void) {
	//标记顶点是否已经在生成数中 图 
	int book[6], graph[6][6];
	//保存生成树到其他各点的距离 
	int dis[6];
	//保存生成树的大小 
	int sum = 0;
	//最大 int 值 认为是无穷值 
	int inf = 214783647;
	int i, j, k, a, b, c, count = 0;
	//最小值 
	int min; 
	//有多少个顶点以及多少条边 
	int n, m;
	//获取顶点数和边数
	scanf("%d %d", &n, &m); 
	
	//初始化标记
	for (i = 0; i < n; i++) {
		book[i] = 0;
	} 
	//初始化图 
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) {
				graph[i][j] = 0;
			} else {
				graph[i][j] = inf;
			}
		}
	}
	//获取图
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
		graph[b][a] = c;
	} 
	//初始化生成树到其他各点的距离
	for (i = 0; i < n; i++) {
		dis[i] = graph[0][i];
	} 
	//将顶点 0 放入到最小生成树中
	book[0] = 1;
	count++;
	while (count < n) {
		//找到离生成树最近的顶点 
		min = inf; 
		for (i = 0; i < n; i++) {
			if (book[i] == 0 && dis[i] < min) {
				min = dis[i];
				j = i;
			}
		}
		book[j] = 1;
		count++;
		sum += min;
		//进行松弛 
		for (i = 0; i < n; i++) {
			if (book[i] == 0 && dis[i] > graph[i][j]) {
				dis[i] = graph[i][j];
			}
		} 
	}
	printf("%d", sum);
	return 0;
}
