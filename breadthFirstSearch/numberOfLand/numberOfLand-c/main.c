#include <stdio.h>
#include <stdlib.h>

/******************************************************** 
问题：现有一张地图，地图上 0 表示海洋，其他数字表示陆地，
计算一共有多少个岛屿，上下左右相连的点表示同一个岛屿
解决：通过广度优先搜素解决 
*********************************************************/

typedef struct QNote {
	//行坐标 
	int x;
	//列坐标 
	int y;
} QNote; 

int main(void) {
	//岛屿的数量
	int numberOfLand = 0; 
	//队列 
	QNote *q; 
	int head, tail; 
	//地图以及标记 
	int **map, **book;
	//广度优先搜索下一步尝试走的位置
	int tmpx, tmpy; 
	//辅助变量
	int i, j, k; 
	//地图的大小
	int n, m; 
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
	//初始队列
	q = (QNote *)malloc(sizeof(QNote) * n * m);
	head = 0;
	tail = 0;
	//枚举地图上的点
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			//枚举到的点是陆地且没有走过
			//说明是一个新的岛屿 
			if (map[i][j] && book[i][j] == 0) {
				//岛屿的数量加一
				numberOfLand++;
				//将起点置入队列并标志已经经过 
				q[tail].x = i;
				q[tail].y = j;
				tail++;
				map[i][j] = numberOfLand;
				book[i][j] = 1; 
				//进行广度优先搜索
				while (head < tail) {
					for (k = 0; k < 4; k++) {
						//下一步尝试走位置 
						tmpx = q[head].x + next[k][0];
						tmpy = q[head].y + next[k][1];
						//判断是否越界
						if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
							continue;
						} 
						if (map[tmpx][tmpy] && book[tmpx][tmpy] == 0) {
							//标记已经走过 
							book[tmpx][tmpy] = 1;
							//对其进行染色
							map[tmpx][tmpy] = numberOfLand;
							//添加到队列中 
							q[tail].x = tmpx;
							q[tail].y = tmpy;
							tail++;
						}
					}
					head++;
				}
				//还原队列 
				head = 0;
				tail = 0; 
			}
		}
	} 
	//打印岛屿的数量
	printf("%d\n", numberOfLand);
	//打印染色后的地图 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%2d", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
