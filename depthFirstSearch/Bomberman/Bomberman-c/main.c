#include <stdio.h>
#include <stdlib.h>

/*************************************
问题：什么位置放置炸弹可以消灭最多敌人
且炸弹人要能够到达，使用 # 表示墙, G 
表示敌人, . 表示空地，只有空地可以放置
炸弹，炸弹不能穿过墙 
解决：使用广度优先搜索 
*************************************/
//最大值以及最大值的坐标 
int max = 0, x, y;
//地图的大小
int m, n; 

/**
* 获取地图上某个点能消灭敌人的个数
* @Param x 行坐标
* @Param y 列坐标
* @Param map 地图
* @Return 消灭敌人的总数 
*/
int getSum(int x, int y, char **map) {
	int sum, i, j;
	sum = 0;
	//往下走 
	i = x, j = y;
	while (map[i][j] != '#') {
		i++;
		if (map[i][j] == 'G') {
			sum++;
		} 
	}
	//往上走 
	i = x, j = y;
	while (map[i][j] != '#') {
		i++;
		if (map[i][j] == 'G') {
			sum++;
		} 
	}
	//往右走 
	i = x, j = y;
	while (map[i][j] != '#') {
		j++;
		if (map[i][j] == 'G') {
			sum++;
		} 
	}
	//往左走 
	i = x, j = y;
	while (map[i][j] != '#') {
		j--;
		if (map[i][j] == 'G') {
			sum++;
		} 
	}
	return sum; 
}

void dfs(int startx, int starty, char **map, int **book) {
	int sum, i, j, tmpx, tmpy;
	//下一步可以走的地方 
	int next[4][2] = {
						{0, 1}, //向右走 
						{1, 0}, //向下走 
						{0, -1}, //向左走 
						{-1, 0} //向上走 
					}; 
	//获取该点在地图上能消灭的敌人的总数 
	sum = getSum(startx, starty, map);
	if (sum > max) {
		max = sum;
		x = startx;
		y = starty;
	}
	for (i = 0; i < 4; i++) {
		//下一步尝试走的坐标 
		tmpx = startx + next[i][0];
		tmpy = starty + next[i][1];
		//判断是否越界
		if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
			continue;
		}
		//判断是否空地
		if (map[tmpx][tmpy] == '.' && book[tmpx][tmpy] == 0) {
			book[tmpx][tmpy] = 1;
			dfs(tmpx, tmpy, map, book);
		} 
	} 
	return;
}

int main(void) {
	//地图 
	char **map;
	//标记 
	int **book;
	//辅助变量 
	int i, j, startx, starty; 
	//输入地图的大小 
	scanf("%d %d", &n, &m);
	//动态创建二维数组给地图使用 
	map =(char **)malloc(sizeof(char *) * n);  
    for(i = 0; i < n; i++) {
    	map[i] = (char *)malloc(sizeof(char) * m); 
	}
	//读取地图
	for (i = 0; i < n; i++) {
		scanf("%s", map[i]);
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
	//获取起点
	scanf("%d %d", &startx, &starty);
	//从起点开始进行深度优先搜索 
	dfs(startx, starty, map, book);
	//打印结果 
	printf("在点 (%d, %d) 处最多可以消灭 %d 个敌人", x, y, max); 
	return 0;
}
