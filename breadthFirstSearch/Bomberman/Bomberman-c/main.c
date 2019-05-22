#include <stdio.h>
#include <stdlib.h>

/*************************************
问题：什么位置放置炸弹可以消灭最多敌人
且炸弹人要能够到达，使用 # 表示墙, G 
表示敌人, . 表示空地，只有空地可以放置
炸弹，炸弹不能穿过墙 
解决：使用广度优先搜索 
*************************************/
typedef struct QNote {
	//行坐标 
	int x;
	//列坐标
	int y; 
} QNote; 

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

int main(void) {
	//队列 
	QNote *q;
	//地图
	char **map;
	//标志 
	int **book;
	//辅助变量 地图大小 起点 队列的起点和终点 
	int i, j, n, m, startx, starty, head, tail, tmpx, tmpy;
	//最大值 某个点可以消灭的敌人总数 最大值所在的坐标 
	int max, sum, x, y; 
	//下一步可以走的地方 
	int next[4][2] = {
						{0, 1}, //向右走 
						{1, 0}, //向下走 
						{0, -1}, //向左走 
						{-1, 0} //向上走 
					}; 
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
	//判断起点位置是否设置正确 
	if (map[startx][starty] == '#' || map[startx][starty] == 'G') {
		printf("不能将炸弹人放置在墙或敌人处！");
		return 0;
	}
	//初始化队列 
	head = 0;
	tail = 0; 
	//给队列分配空间 
	q = (QNote *)malloc(n * m * sizeof(QNote));
	//从起点开始出发
	book[startx][starty] = 1;
	q[tail].x = startx;
	q[tail].y = starty;
	tail++;
	max = getSum(startx, starty, map);
	x = startx;
	y = starty; 
	//开始广度优先搜索
	while (head < tail) {
		for (i = 0; i < 4; i++) {
	 		//尝试进入下一步 
			tmpx = q[head].x + next[i][0];
			tmpy = q[head].y + next[i][1];
			//判断是否越界
			if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
				continue;
			} 
			//判断是否是空地和是否已经走过
			if (map[tmpx][tmpy] == '.' && book[tmpx][tmpy] == 0) {
				//将点添加到队列中并标志已经过 
				book[tmpx][tmpy] = 1;
				q[tail].x = tmpx;
				q[tail].y = tmpy;
				tail++;
				//获取该点上能消灭的敌人总数 
				sum = getSum(tmpx, tmpy, map);
				if (sum > max) { 
					x = tmpx;
					y = tmpy;
					max = sum;
				}
			} 
		} 
		//进入下一次广度优先搜索 
		head++;
	} 
	printf("在点 (%d, %d) 处最多可以消灭 %d 个敌人", x, y, max); 
	return 0;
}

