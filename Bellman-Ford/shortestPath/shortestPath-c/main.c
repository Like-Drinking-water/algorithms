#include <stdio.h>
#include <stdlib.h>

/****************************************************
问题：解决单源最短路径(含负权)
解决：使用 Bellman-Ford 算法 
****************************************************/

int main(void) {
	//标记是否松弛完成还有检测负权回路 
	int flag;
	//int 最大值
	int inf = 214783647; 
	//分别表示起点，终点跟权值 
	int *u, *v, *w;
	//记录单元最短路径 
	int *dis;
	//表示有几个顶点 已经几条边
	int n, m, s;
	//辅助变量
	int i, j; 
	//获取顶点与边数还有起点 
	scanf("%d %d %d", &n, &m, &s);
	//初始化图
	u = (int *)malloc(sizeof(int) * m);
	v = (int *)malloc(sizeof(int) * m);
	w = (int *)malloc(sizeof(int) * m); 
	//获取图信息
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	}
	//初始化单源最短路径
	dis = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		if (i == s) {
			dis[s] = 0;
		} else {
			dis[i] = inf;
		}
	}
	//Bellman-Ford 算法核心代码
	for (i = 0; i < n - 1; i++) {
		flag = 0; 
		for (j = 0; j < m; j++) {
			if (dis[u[j]] < inf && dis[v[j]] > dis[u[j]] + w[j]) {
				dis[v[j]] = dis[u[j]] + w[j];
				flag = 1;
			}
		}
		//表示松弛完成 
		if (!flag) {
			break;
		}
	} 
	//检测负权回路 
	flag = 0;
	for (i = 0; i < m; i++) {
		if (dis[u[i]] < inf && dis[v[i]] > dis[u[i]] + w[i]) {
			dis[v[i]] = dis[u[i]] + w[i];
			flag = 1;
		}
	} 
	if (flag) {
		printf("此图含有负权回路");
	}
	//打印结果
	for (i = 0; i < n; i++) {
		printf("%d ", dis[i]);
	} 
	return 0;
}
