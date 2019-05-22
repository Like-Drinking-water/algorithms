#include <stdio.h>
#include <stdlib.h>

/******************************************************** 
问题：现有一张地图，地图上 0 表示海洋，其他数字表示陆地，
通过着陆的点计算着陆岛屿的面积(即多少个格子)，上下左右相连
的点表示同一个岛屿
解决：通过广度优先搜素解决 
*********************************************************/
//地图的大小 
#define N 10
#define M 10 
#define AREA N * M

typedef struct QNote {
	int x;
	int y;
} QNote; 

int main(void) {
	//地图 
	int map[N][M];
	//标志 
	int book[N][M];
	QNote q[AREA]; 
	//辅助变量 着陆的坐标 队列头指针 陆地面积 
	int i, j, landingx, landingy, tmpx, tmpy, head, tail, area = 0;
	//下一步可以走的地方 
	int next[4][2] = {
						{0, 1}, //向右走 
						{1, 0}, //向下走 
						{0, -1}, //向左走 
						{-1, 0} //向上走 
					}; 
	//输入着陆的位置
	scanf("%d %d", &landingx, &landingy);
	//获取地图
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	} 
	//判断着陆地点是否是海洋
	if (!map[landingx][landingy]) {
		printf("你掉到海中了！");
		return 0;
	} 
	//初始化标志 
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			book[i][j] = 0; 
		}
	} 
	//初始化队列
	head = 0;
	tail = 0;
	q[tail].x = landingx;
	q[tail].y = landingy;
	//标志着陆点以及来过 
	book[landingx][landingy] = 1;
	tail++;
	area++; 
	//开始广度优先搜索 
	while (head < tail) {
		for (i = 0; i < 4; i++) {
			//下一步尝试走的位置 
			tmpx = q[head].x + next[i][0];
			tmpy = q[head].y + next[i][1];
			//判断是否越界
			if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M) {
				continue;
			}
			//判断是否是陆地
			if (map[tmpx][tmpy] && book[tmpx][tmpy] == 0) {
				//标志已经走过
				book[tmpx][tmpy] = 1;
				q[tail].x = tmpx;
				q[tail].y = tmpy;
				tail++;
				area++;
			}
		}
		head++;
	}
	printf("%d", area);
	return 0;
}
