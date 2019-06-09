#include <stdio.h>
#include <stdlib.h>

/****************************************
最小生成树问题(通过最小堆进行优化) 
*****************************************/
//堆 
int heap[10], size;
//顶点在堆中的位置 
int pos[10];
//生成树到其他各点的距离 
int dis[10]; 

void swap(int i, int j) {
	int tmp;
	//交换堆中顶点的位置 
	tmp = heap[i];
	heap[i] = heap[j];
	heap[j] = tmp;
	//修改记录堆中顶点的位置
	tmp = pos[heap[i]];
	pos[heap[i]] = pos[heap[j]];
	pos[heap[j]] = tmp;
} 

void siftDown(int i) {
	//标记是否还需要继续调整 
	int flag = 0;
	int tmp;
	while (i * 2 <= size && flag == 0) {
		//如果他的左儿子比他小 
		if (dis[heap[i * 2]] < dis[heap[i]]) {
			tmp = i * 2;
		}
		//如果他比他的左儿子小 
		else {
			tmp = i;
		}
		//如果他有右儿子 
		if (i * 2 + 1 <= size) {
			//如果他的右儿子比他小
			if (dis[heap[i * 2 + 1]] < dis[heap[i]]) {
				tmp = i * 2 + 1;
			} 
		} 
		//如果他比两个儿子都小说明不用再做调整 
		if (tmp == i) {
			flag = 1;
		} 
		//如果还没调整完成
		//则与较小的儿子交换位置
		//并以交换的位置进行下一次调整 
		else {
			swap(i, tmp);
			i = tmp;
		}
	} 
}

void siftUp(int i) {
	//标记是否调整完成 
	int flag = 0;
	//如果是堆顶则无需调整
	if (i == 1) {
		return;
	} 
	//进行调整
	while (i != 1 && flag == 0) {
		//如果他的父亲比他大 则与其父亲交换位置 
		if (dis[heap[i]] < dis[heap[i / 2]]) {
			swap(i, i / 2); 
		}
		//否则说明已经调整完成 
		else {
			flag = 1; 
		} 
		i = i / 2;
	} 
	
} 

int pop() {
	int i;
	i = heap[1];
	heap[1] = heap[size];
	pos[heap[1]] = 1;
	size--;
	siftDown(1);
	return i;
}

int main(void) {
	//保存图的信息 
	int u[20], v[20], w[20];
	//邻接表 
	int next[20], first[20];
	//顶点数以及边数 
	int n, m;
	//记录加入生成树的顶点数量 
	int count = 0;
	//最大 int 值 认为是无穷值 
	int inf = 214783647;
	//生成树的大小
	int sum = 0; 
	int i, j;
	//标记是否以及加入生成树 
	int book[20];
	//获取顶点数以及边数
	scanf("%d %d", &n, &m);
	//初始化标记
	for (i = 1; i <= n; i++) {
		book[i] = 0;
	} 
	//获取图
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	} 
	for (i = 1; i <= m; i++) {
		u[i + m] = v[i];
		v[i + m] = u[i];
		w[i + m] = w[i]; 
	}
	//创建邻接表
	for (i = 1; i <= n; i++) {
		first[i] = -1;
	} 
	for (i = 1; i <= 2 * m; i++) {
		next[i] = first[u[i]];
		first[u[i]] = i;
	}
	//将 1 号顶点加入生成树
	book[1] = 1;
	count++;
	//初始化生成树到其他顶点的距离 
	dis[1] = 0;
	for (i = 2; i <= n; i++) {
		dis[i] = inf;
	}
	i = first[1];
	while (i != -1) {
		dis[v[i]] = w[i];
		i = next[i];
	} 
	//初始化堆
	size = n;
	for (i = 1; i <= n; i++) {
		heap[i] = i;
		pos[i] = i;
	} 
	for (i = n / 2; i > 0; i--) {
		siftDown(i);
	}
	//让一号顶点出堆 
	pop();
	while (count < n) {
		//获取堆顶的顶点 
		i = pop();
		book[i] = 1;
		count++;
		sum += dis[i]; 
		//遍历该顶点的所有边 
		j = first[i];
		while (j != -1) {
			//进行松弛 
			if (book[v[j]] == 0 && dis[v[j]] > w[j]) {
				dis[v[j]] = w[j];
				siftUp(pos[v[j]]);
			}
			j = next[j];
		}
	} 
	printf("%d", sum);
	return 0;
}
