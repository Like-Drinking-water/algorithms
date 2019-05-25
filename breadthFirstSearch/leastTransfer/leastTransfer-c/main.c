#include <stdio.h>
#include <stdlib.h>

/******************************************************
问题：用图来表示不同的站，1 表示两个站可以互相到达，-1 
表示两个站不能直接到达，0 表示同一个点，现要求算出起点
到终点最少换乘的路线 
解决：广度优先算法 
*******************************************************/ 
typedef struct {
	int node;
	int before;
} QNode;

int main(void) {
	//图中节点以及边数的数量 
	int n, m;
	//起点站与终点站
	int start, end;
	//用来保存路线的图，已经保存已走路线
	int **graph, *book;
	//辅助变量以及临时存储变量
	int i, j, a, b; 
	//标记是否找到终点 
	int flag;
	//路径 
	int *path;
	//队列
	QNode *q;
	int head, tail;
	//获取节点的数量以及边数还有起点跟终点 
	scanf("%d %d %d %d", &n, &m, &start, &end); 
	//给图创建空间 
	graph = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++) {
		graph[i] = (int *)malloc(sizeof(int) * n);
	}
	//给标记创建空间
	book = (int *)malloc(sizeof(int) * n);
	//获取节点关系
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			//两个相同的点的距离为0 
			if (i == j) {
				graph[i][j] = 0;
			}
			//其他点初始化为 -1 
			else {
				graph[i][j] = -1;
			}
		}
	}
	//获取可以到达的点 
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[a][b] = 1;
	} 
	//初始化标记
	for (i = 0; i < n; i++) {
		book[i] = 0;
	} 
	//给路径分配空间
	path = (int *)malloc(sizeof(int) * n); 
	//初始化队列
	q = (QNode *)malloc(sizeof(QNode) * n);
	head = 0;
	tail = 0;
	//从起点开始进行广度优先搜索
	book[start] = 1;
	q[tail].node = start;
	q[tail].before = -1;
	tail++;
	while(head < tail) {
		for (i = 0; i < n; i++) {
			//如果能到达该点且该点没有走过 
			if (graph[q[head].node][i] == 1 && book[i] == 0) {
				q[tail].node = i;
				q[tail].before = head;
				tail++; 
				//找到终点即可退出 
				if (i == end) {
					flag = 1;
					break;
				}
				book[i] = 1;
			} 
		}
		head++;
		if (flag) {
			break;
		} 
	} 
	//有路径能够到达终点 
	if (flag) {
		i = tail - 1;
		j = 0;
		//获取路径 
		while (i != -1) {
			path[j] = q[i].node;
			j++;
			i = q[i].before;
		}
		//打印路径 
		while (j > 1) {
			j--;
			printf("%d -> ", path[j]);
		}
		printf("%d", end);
	} 
	//没有路径能够到达终点 
	else {
		printf("没有路径能够到达终点"); 
	} 
	return 0;
}
