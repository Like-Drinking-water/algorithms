#include <stdio.h>
#include <stdlib.h>

/************************************************
问题：在一个二维地图中，以最短路径走到终点，其中 0
表示空地，1 表示障碍物
解决：使用深度优先搜索 
************************************************/ 
//用来记录最短路径 
int min = 2147483647; 
//用来表示地图的大小
int n, m; 

/**
* 进行深度优先搜索 搜索终点
* @Param startx 开始行坐标
* @Param starty 开始列坐标
* @Param endx 终点行坐标
* @Param endy 终点列坐标
* @Param step 已经走的步数
* @Param map 地图
* @Param book 标记已走路径 
*/
void dfs(int startx, int starty, int endx, int endy, int step, int **map, int **book) {
	int i;
	int tmpx, tmpy; 
	int next[4][2] = {
						{0, 1}, //向右走 
						{1, 0}, //向下走 
						{0, -1}, //向左走 
						{-1, 0} //向上走 
					}; 
	//判断是否已经到达终点 
	if (startx == endx && starty == endy) {
		//到达终点且路径比已经走过的路径更短 
		if (step < min) {
			min = step;
		}
		return;
	}
	for (i = 0; i < 4; i++) {
		//确定下一步的位置 
		tmpx = startx + next[i][0];
		tmpy = starty + next[i][1];
		//判断是否越界 如果越界则跳过这次前进 
		if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
			continue;
		}
		//判断是否已经走过和下一处是不是空地 
		if (book[tmpx][tmpy] == 0 && map[tmpx][tmpy] == 0) {
			//进入后标记已经走过 
			book[tmpx][tmpy] = 1; 
			//进入下一个点 
			dfs(tmpx, tmpy, endx, endy, step + 1, map, book);
			//回来后取消标记
			book[tmpx][tmpy] = 0; 
		}
		
	}
	return;
}

int main() {
	//用来表示地图和标记走过的路径 
	int **map, **book;
	//起点和终点坐标 
	int startx, starty, endx, endy; 
	int i, j;
	//输入地图的大小 
	scanf("%d %d", &n, &m);
	//动态创建二维数组给地图使用 
	map =(int **)malloc(sizeof(int*) * n);  
    for(i = 0; i < n; i++) {
    	map[i] = (int *)malloc(sizeof(int) * m); 
	} 
    //读取地图
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	//动态创建二维数组给路径标记使用 
	book =(int **)malloc(sizeof(int*) * n);  
    for(i = 0; i < n; i++) {
    	book[i] = (int *)malloc(sizeof(int) * m); 
	} 
    //初始化标记 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			book[i][j] = 0;
		}
	}
	//获取起点与终点 
	scanf("%d %d %d %d", &startx, &starty, &endx, &endy);
	//从起点开始搜索
	//标记起点已经走过 
	book[startx][starty] = 1; 
	dfs(startx, starty, endx, endy, 0, map, book);
	//打印最短路径的大小
	printf("%d", min); 
	return 0;
}

