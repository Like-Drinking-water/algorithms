#include <stdio.h>
#include <stdlib.h>

/******************************************************** 
问题：现有一张地图，地图上 0 表示海洋，其他数字表示陆地，
通过着陆的点计算着陆岛屿的面积(即多少个格子)，上下左右相连
的点表示同一个岛屿
解决：通过深度优先搜素解决 
*********************************************************/
//着陆位置的面积 
int area = 0;
//地图的大小 
int n, m; 

/**
* 深度优先搜索
* @Param x 行坐标
* @Param y 列坐标
* @Param color 要染的颜色 
* @Param map 地图
* @Param book 标记 
*/
void dfs(int x, int y, int color, int **map, int **book) {
	int i, tmpx, tmpy;
	//下一步可以走的地方 
	int next[4][2] = {
						{0, 1}, //向右走 
						{1, 0}, //向下走 
						{0, -1}, //向左走 
						{-1, 0} //向上走 
					}; 
	area++;
	map[x][y] = color;
	for (i = 0; i < 4; i++) {
		//下一步尝试走的位置 
		tmpx = x + next[i][0];
		tmpy = y + next[i][1];
		//判断是否越界
		if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
			continue;
		} 
		//判断下一步是否是陆地而且还没有经过 
		if (map[tmpx][tmpy] && book[tmpx][tmpy] == 0) {
			//标记经过
			book[tmpx][tmpy] = 1;
			//进入下一步
			dfs(tmpx, tmpy, color, map, book); 
		} 
	}
	return;
} 

int main(void) {
	//着陆点 
	int landingx, landingy;
	//地图以及标志
	int **map, **book; 
	//辅助变量 
	int i, j;
	//输入地图的大小 
	scanf("%d %d", &n, &m);
	//动态创建二维数组给地图使用 
	map =(int **)malloc(sizeof(int *) * n);  
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
	book =(int **)malloc(sizeof(int *) * n);  
    for(i = 0; i < n; i++) {
    	book[i] = (int *)malloc(sizeof(int) * m); 
	}
    //初始化标记 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			book[i][j] = 0;
		}
	}
	//获取着陆点
	scanf("%d %d", &landingx, &landingy);
	//判断着陆地点是否是海洋
	if (!map[landingx][landingy]) {
		printf("你掉到海中了！");
		return 0;
	} 
	//开始深度优先搜索 
	book[landingx][landingy] = 1;
	dfs(landingx, landingy, -1, map, book);
	//展示面积 
	printf("%d\n", area);
	//展示染色后的地图
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d\t", map[i][j]);
		}
		printf("\n"); 
	}
	return 0;
}
