#include <stdio.h>
#include <stdlib.h>

/********************************************
问题：寻找割点 
*********************************************/ 
int root;
//表示某顶点能够到达的最早的时间戳以及到达该顶点的时间戳 
int low[20], num[20];
//图 
int graph[20][20];
//用来记录时间戳 
int count;
//图中的顶点数以及边数 
int n, m;
//标记是否是割点 
int flag[20];

//最小值 
int min(int x, int y) {
	return x > y ? y : x; 
}

void dfs(int cur, int father) {
	//用来记录孩子的数量 
	int child = 0, i;
	//记录到达时候的时间戳 
	count++; 
	num[cur] = count;
	low[cur] = count;
	//遍历能够达到的点 
	for (i = 0; i < n; i++) {
		if (graph[cur][i] == 1) {
			//表示还没到过这个点 
			if (num[i] == 0) {
				dfs(i, cur);
				child++;
				//更新当前顶点能够到达的最早时间戳 
				low[cur] = min(low[cur], low[i]);
				//如果 cur 不是根结点 且 i 能够到达的最早时间戳大于 cur 的时间戳
				//则表明 cur 是割点
				if (cur != root && low[i] >= num[cur]) {
					flag[cur] = 1; 
				}
				//如果是根结点 则需要两个或两个以上的孩子才是割点
				if (cur == root && child >= 2) {
					flag[cur] = 1;	
				} 
			} 
			//如果到过这个点 且这个点不是当前顶点 
			else if (i != father) {
				low[cur] = min(low[cur], num[i]);
			}
		}
	} 
} 

int main(void) {
	int i, j, x, y;
	//获取顶点数以及边数 
	scanf("%d %d", &n, &m);
	//初始化图
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			graph[i][j] = 0;
		} 
	} 
	//获取图
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	} 
	root = 0;
	//从 0 号顶点开始深度搜搜
	dfs(0, root);
	for (i = 0; i < n; i++) {
		if (flag[i] == 1) {
			printf("%d ", i);
		}
	} 
	return 0;
}
