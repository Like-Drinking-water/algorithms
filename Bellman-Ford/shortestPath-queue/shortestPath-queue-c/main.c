#include <stdio.h>
#include <stdlib.h>

/****************************************************
问题：解决单源最短路径(含负权)
解决：使用 Bellman-Ford 算法(使用队列进行优化) 
****************************************************/

int main(void) {
	//最大 int 值 认为是无穷值 
	int inf = 214783647;
	//邻接表
	int *first, *next;
	//起点终点以及权值 
	int *u, *v, *w; 
	//标记某个节点是否已经进入队列 
	int *book;
	//队列
	int queue[100], head, tail;
	//记录单源最短路径
	int *dis;
	//节点个数以及边数起点 
	int n, m, s; 
	//辅助变量
	int i, j, k; 
	//获取节点个数边数以及起点
	scanf("%d %d %d", &n, &m, &s);
	//初始化单源最短路径
	dis = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		if (i == s) {
			dis[i] = 0;
		} else {
			dis[i] = inf;
		}
	} 
	//初始化邻接表
	u = (int *)malloc(sizeof(int) * m); 
	v = (int *)malloc(sizeof(int) * m);
	w = (int *)malloc(sizeof(int) * m);
	first = (int *)malloc(sizeof(int) * n);
	next = (int *)malloc(sizeof(int) * m);
	//初始化 
	for (i = 0; i < n; i++) {
		first[i] = -1; 
	}
	//获取图的数据
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		next[i] = first[u[i]];
		first[u[i]] = i;
	} 
	//初始化标记
	book = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		book[i] = 0;
	} 
	//初始化队列
	head = 0;
	tail = 0;
	//将起点放入队列中并标记已入队 
	queue[tail] = s;
	tail++;
	book[s] = 1; 
	while (head < tail) {
		k = first[queue[head]];
		while (k != -1) {
			if (dis[v[k]] > dis[u[k]] + w[k]) {
				dis[v[k]] = dis[u[k]] + w[k];
				//还没有入队 
				if (book[v[k]] == 0) {
					queue[tail] = v[k];
					tail++;
					book[v[k]] = 1;
				}
			}
			k = next[k];
		}
		//出队
		book[queue[head]] = 0;
		head++;
	} 
	//打印结果 
	for (i = 0; i < n; i++) {
		printf("%d ", dis[i]);
	} 
	return 0;
}
