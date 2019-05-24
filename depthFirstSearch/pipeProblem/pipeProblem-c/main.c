#include <stdio.h>
#include <stdlib.h>

/******************************************************
问题：水管连接问题，通过转动水管使水能够从入口流到出口
水管分为弯管跟直管
↓       ↑→→    →→↓      ↑             ↓ 
↓→→     ↑        ↓    →→↑    ←←←      ↓      树 
  1      2      3      4      5       6      0(表示障碍)
 箭头不表示水流动方向 只表示水管的形状
解决：深度优先搜素 
*******************************************************/
typedef struct Node {
	int x;
	int y;
} Node; 
//地图的大小 
int n, m;
//找到出口的标志
int flag = 0; 
//用保存路径 
Node *node;
//最后一个元素的位置 
int top = 0;
/**
* 深度优先搜索
* @Param x 行坐标
* @Param y 列坐标
* @Param front 水来的方向(1 表示左边;2 表示右边;3 表示上边;4 表示下边) 
* @Param map 地图
* @Param book 标记已走的路线 
*/
void dfs(int x, int y, int front, int **map, int **book) {
	int i;
	if (x == n - 1 && y == m) {
		flag = 1;
		for (i = 0; i < top; i++) {
			printf("(%d, %d) ", node[i].x, node[i].y);
		}
		return;
	} 
	//判断是否越界
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return;
	} 
	//判断这个水管是否在路径中已经走过 
	if (book[x][y] == 1) {
		return;
	}
	//标记该点已经走过 
	book[x][y] = 1;
	node[top].x = x;
	node[top].y = y;
	top++;
	//表示弯管 
	if (map[x][y] >= 1 && map[x][y] <= 4) { 
		/* 
		//水的方向从左边来 
		if (front == 1) {
			//水流到下边 
			dfs(x + 1, y, 3, map, book); //3号管 
			//水流到上边
			dfs(x - 1, y, 4, map, book); //4号管 
		}
		//水的方向从右边来 
		if (front == 2) {
			//水流到下边 
			dfs(x + 1, y, 3, map, book); //2号管 
			//水流到上边 
			dfs(x - 1, y, 4, map, book); //1号管 
		}
		//水的方向从上边来 
		if (front == 3) {
			//水流到左边 
			dfs(x, y - 1, 2, map, book); //4号管 
			//水流到右边 
			dfs(x, y + 1, 1, map, book); //1号管 
		}
		//水的方向从下边来 
		if (front == 4) {
			//水流到左边 
			dfs(x, y - 1, 2, map, book); //3号管 
			//水流到右边 
			dfs(x, y + 1, 1, map, book); //2号管 
		}
		*/ 
		//水的方向从左边或右边来 
		if (front == 1 || front == 2)  {
			//水流到下边 
			dfs(x + 1, y, 3, map, book); //3号管 | 2号管 
			//水流到上边
			dfs(x - 1, y, 4, map, book); //4号管 | 1号管 
		}
		//水的方向从上边或下边来 
		if (front == 3 || front == 4) {
			//水流到左边 
			dfs(x, y - 1, 2, map, book); //4号管 | 3号管 
			//水流到右边 
			dfs(x, y + 1, 1, map, book); //1号管 | 2号管 
		} 
	} 
	//表示直管 
	if (map[x][y] == 5 || map[x][y] == 6) {
		//水的方向从左边来 
		if (front == 1) {
			dfs(x, y + 1, 1, map, book); //5号管 
		} 
		//水的方向从右边来 
		if (front == 2) {
			dfs(x, y - 1, 2, map, book); //5号管 
		} 
		//水的方向从上边来 
		if (front == 3) {
			dfs(x + 1, y, 3, map, book); //6号管 
		} 
		//水的方向从下边边来 
		if (front == 4) {
			dfs(x - 1, y, 4, map, book); //6号管 
		} 
	}
	//当一条路径走完后将标记取消 
	book[x][y] = 0;
	top--;
	return; 
} 

int main(void) {
	
	//地图以及已走标记 
	int **map, **book; 
	//辅助变量 
	int i, j; 
	//获取地图的大小 
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
	//为路径节点开辟空间 
	node = (Node *)malloc(sizeof(Node) * n * m);
	//开始深度优先搜素 
	dfs(0, 0, 1, map, book); 
	if (!flag) {
		printf("没有一条路径能够到达出水口"); 
	}
	return 0;
}
