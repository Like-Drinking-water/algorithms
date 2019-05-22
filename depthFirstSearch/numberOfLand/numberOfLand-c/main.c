#include <stdio.h>
#include <stdlib.h>

/******************************************************** 
问题：现有一张地图，地图上 0 表示海洋，其他数字表示陆地，
计算一共有多少个岛屿，上下左右相连的点表示同一个岛屿
解决：通过深度优先搜素解决 
*********************************************************/

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
	int i;
	int tmpx, tmpy; 
	//下一步可以走的地方 
	int next[4][2] = {
						{0, 1}, //向右走 
						{1, 0}, //向下走 
						{0, -1}, //向左走 
						{-1, 0} //向上走 
					}; 
	//染色 
	map[x][y] = color;
	for (i = 0; i < 4; i++) {
		//下一步尝试要走的地方 
		tmpx = x + next[i][0];
		tmpy = y + next[i][1];
		//判断下一步是否越界 
		if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
			continue;
		} 
		//判断是否是陆地且是否走过
		if (map[tmpx][tmpy] && book[tmpx][tmpy] == 0) {
			//标记已经走过 
			book[tmpx][tmpy] = 1;
			//进入下一步
			dfs(tmpx, tmpy, color, map, book); 
		} 
	}
	return;
} 

int main(void) {
	int numberOfLand = 0;
	//辅助变量
	int i, j; 
	//地图以及标记 
	int **map, **book;
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
	//枚举地图上的位置 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			//如果没有去过这块地方且地图上这块地方是陆地
			//则表明是一个新的岛屿 
			if (map[i][j] && book[i][j] == 0) {
				numberOfLand++;
				dfs(i, j, numberOfLand, map, book); 
			}
		}
	}
	//打印岛屿的数量 
	printf("%d\n", numberOfLand);
	//并染色后的岛屿 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%2d", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
