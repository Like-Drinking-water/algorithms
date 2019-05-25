#include <stdio.h>
#include <stdlib.h>

/*******************************************************
问题：图的遍历，用二维数组保存图中节点的关系。-1 表示无法
到达;0 表示距离为 0;1 表示可以到达
解决：广度优先算法 
********************************************************/

int main(void) {
	//图的节点个数以及边数 
	int n, m;
	//辅助变量以及临时存储变量
	int i, j, a, b;
	//图以及标记
	int **graph, *book;
	//队列 
	int *q;
	int head = 0, tail = 0; 
	//输入节点的数量以及边数 
	scanf("%d %d", &n, &m); 
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
	//初始化队列
	q = (int *)malloc(sizeof(int) * n); 
	q[0] = 0;
	tail++;
	book[0] = 1;
	printf("从 0 号节点开始遍历\n");
	while (head < tail) {
		for (i = 0; i < n; i++) {
			//如果可以到达下一个点且下一个点没有走过 
			if (graph[q[head]][i] == 1 && book[i] == 0) {
				//添加标记表示以及走过 
				book[i] = 1;
				printf("到 %d 号节点\n", i);
				q[tail] = i;
				tail++; 
			}
		}
		head++;
	}
	return 0;
}
