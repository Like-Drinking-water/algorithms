#include <stdio.h>
#include <stdlib.h>

/**********************************
寻找图中的割边 
**********************************/
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
	int i;
	//记录时间戳 
	count++;
	num[cur] = count;
	low[cur] = count;
	//遍历所有能够到达的点 
	for (i = 0; i < n; i++) {
		if (graph[cur][i] == 1) {
			//表示还没有经过 
			if (num[i] == 0) {
				//进入子节点继续深度优先搜索 
				dfs(i, cur); 
				//更新能够到达的最早时间戳
				low[cur] = min(low[i], low[cur]);
				//表示不经过父节点回不到父亲也回不到祖先
				//说明 cur - i 是割边 
				if (low[i] > num[cur]) {
					printf("%d - %d\n", cur, i);
				} 
			} 
			//如果以及经过且不是父节点 则更新能够到达的最早时间戳 
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
	return 0;
}
