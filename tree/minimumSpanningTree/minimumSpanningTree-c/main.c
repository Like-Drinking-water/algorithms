#include <stdio.h>
#include <stdlib.h>

/*****************************
最小生成树问题 
******************************/ 
//表示两个节点以及之间的权值 
typedef struct {
	int u;
	int v;
	int w;
} Edge; 

int f[10];

void quickSort(Edge *edge, int left, int right) {
	int i, j;
	Edge tmp;
	//表示结束 
	if (left >= right) {
		return;
	}
	i = left;
	j = right;
	while (i != j) {
		//从左边开始寻找比基值大的数 
		while (edge[i].w <= edge[left].w && i < j) {
			i++;
		}
		//从右边开始寻找比基值小的数
		while (edge[j].w >= edge[left].w && i < j) {
			j--;
		} 
		//表示两个点没有相遇 
		if (i < j) {
			tmp = edge[i];
			edge[i] = edge[j];
			edge[j] = tmp; 
		}
	} 
	//交换基值的位置
	tmp = edge[left];
	edge[left] = edge[i];
	edge[i] = tmp; 
	//进行递归
	quickSort(edge, left, i - 1);
	quickSort(edge, i + 1, right);
	return; 
} 

//获取父节点 
int getFather(int v) {
	if (f[v] == v) {
		return v;
	}
	else {
		f[v] = getFather(f[v]);
		return f[v];
	}
}

//合并两个集合的关系 
int merge(int u, int v) {
	int t1, t2;
	t1 = getFather(u);
	t2 = getFather(v);
	if (t1 != t2) {
		f[t2] = t1;
		return 1;
	}
	return 0;
} 

int main(void) {
	int i;
	Edge edge[20];
	int count = 0, sum = 0; 
	//节点数以及边数 
	int n, m;
	//获取节点数与边数
	scanf("%d %d", &n, &m);
	//获取边的权值
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
	}
	//按权值进行从小到大排序 
	quickSort(edge, 0, m - 1);
	//并查集初始化
	for (i = 0; i < n; i++) {
		f[i] = i;
	} 
	//Kruskal 算法核心部分 
	for (i = 0; i < m; i++) {
		//第一次连通 
		if (merge(edge[i].u, edge[i].v)) {
			count++;
			sum += edge[i].w;
		}
		//最小生成树需要有 n - 1 条边 
		if (count == n - 1) {
			break;
		}
	}
	printf("%d", sum); 
	return 0;
}
