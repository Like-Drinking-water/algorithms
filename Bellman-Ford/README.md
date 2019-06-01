# Bellman-Ford 
解决单源最短路径含有负权的问题
## 目录简介
* [shortestPath](https://github.com/Like-Drinking-water/algorithms/tree/master/Bellman-Ford/shortestPath) - 使用 Bellman-Ford 算法找到两点的最短路径
* [shortestPath-queue](https://github.com/Like-Drinking-water/algorithms/tree/master/Bellman-Ford/shortestPath-queue) - 使用 Bellman-Ford 算法找到两点的最短路径, 并通过队列对算法进行优化
## 实现想法
对每一条边进行松弛操作，最短路径最多有 n - 1 条边，所以最多用进行 n - 1 轮对所有边进行松弛
## 关键代码
未使用队列
``` c
for (i = 0; i < n - 1; i++) {
	flag = 0; 
	for (j = 0; j < m; j++) {
		if (dis[u[j]] < inf && dis[v[j]] > dis[u[j]] + w[j]) {
			dis[v[j]] = dis[u[j]] + w[j];
			flag = 1;
		}
	}
	//表示松弛完成 
	if (!flag) {
		break;
	}
} 
```
使用队列
``` c
while (head < tail) {
	k = first[queue[head]];
	while (k != -1) {
		if (dis[v[k]] > dis[u[k]] + w[k]) {
			dis[v[k]] = dis[u[k]] + w[k];
			//还没有入队 
			if (book[v[k]] == 0) {
				queue[tail] = v[k];
				tail++;
				book[v[k]] = 1;
			}
		}
		k = next[k];
	}
	//出队
	book[queue[head]] = 0;
	head++;
} 
```