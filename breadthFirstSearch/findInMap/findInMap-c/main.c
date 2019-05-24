#include <stdio.h>
#include <stdlib.h>

/************************************************
问题：在一个二维地图中，以最短路径走到终点，其中 0
表示空地，1 表示障碍物
解决：使用广度优先搜索 
************************************************/ 

typedef struct QNode {
	//行坐标 
	int x;
	//列坐标 
	int y;
	//父节点的在队列中的编号
	int father;
	//已经走的步数
	int step; 
}QNode; 

typedef struct Path {
	//行坐标 
	int x;
	//列坐标 
	int y;
}Path;


int main(void) {
	//用来保存地图以及标记 
	int **map, **book;
	Path *path; 
	//用来标记队列的起点与终点 
	int head, tail; 
	//用来保存节点 
	QNode *q;
	//辅助变量 地图的大小 起点 终点 临时位置 到达终点的标志 
	int i, j, n, m, startx, starty, endx, endy, tmpx, tmpy, flag; 
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
	//给队列分配空间
	q = (QNode *)malloc(n * m * sizeof(QNode));
	//初始化队列
	head = 0;
	tail = 0;
	//从起点开始搜索
	//向队列中插入起点 
	book[startx][starty] = 1;
	q[tail].x = startx;
	q[tail].x = starty;
	q[tail].father = -1;
	q[tail].step = 0;
	tail++;
	//初始化到达终点的标记
	flag = 0; 
	while (head < tail) {
		for (i = 0; i < 4; i++) {
			tmpx = q[head].x + next[i][0];
			tmpy = q[head].y + next[i][1];
			//判断是否越界 如果越界则跳过这次前进 
			if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
				continue;
			}
			//判断是否已经走过和下一处是不是空地 
			if (book[tmpx][tmpy] == 0 && map[tmpx][tmpy] == 0) {
				//进入后标记已经走过 
				book[tmpx][tmpy] = 1; 
				q[tail].x = tmpx;
				q[tail].y = tmpy;
				q[tail].father = head;
				//在原来的步数上加一 
				q[tail].step = q[head].step + 1;
				tail++;
			}
			if (tmpx == endx && tmpy == endy) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			break;
		}
		head++;
	} 
	//打印一共走了多少步
	printf("%d\n", q[tail - 1].step);
	//创建空间来存放路径
	path = (Path *)malloc((q[tail - 1].step + 1) * sizeof(Path));
	i = tail - 1;
	j = -1;
	//将路径读取到 path 中 
	while (i != -1) {
		j++;
		path[j].x = q[i].x;
		path[j].y = q[i].y;
		i = q[i].father;
	}
	//打印路径 
	while (j != -1) {
		printf("(%d, %d)",path[j].x, path[j].y); 
		if (j) {
			printf(" -> ");
		}
		j--;	
	}
	
	//打印路径 
	return 0;
}
