# Dijkstra 
单源最短路径
## 目录简介
* [shortestPath](https://github.com/Like-Drinking-water/algorithms/tree/master/Dijkstra/shortestPath) - 使用 Dijkstra 算法找到两点的最短路径
## 实现想法
1. 每找到已知的最短路径的顶点，将其分为 P 集合，用 book[i] = 1 来标记，其他分为 Q 集合
2. 将图的关系赋给 dis, 表示源点到某个点的距离
3. 每次从集合 Q 中找出离源点最近的顶点 u, 加入到 P 。并考察所有以点 u 为起点的边，对每一条边进行松弛操作。
4. 重复第三步操作，dis 中的值就是源点到各个顶点的最小值
## 关键代码
``` c
for (i = 0; i < n - 1; i++) {
	min = inf;
	//找到离源点最近的点 
	for (j = 0; j < n; j++) {
		if (book[j] == 0 && dis[j] < min) {
			min = dis[j];
			u = j;
		}
	} 
	book[u] = 1;
	if (last == 1) {
		path[u][last] = u;
	}
	last++;
	for (v = 0; v < n; v++) {
		//表示能够到达 
		if (graph[u][v] < inf) {
			if (book[v] == 0 && dis[v] > min + graph[u][v]) {
				dis[v] = min + graph[u][v];
				//合成路径 
				for (j = 0; j < last; j++) {
					path[v][j] = path[u][j];
				}
				path[v][last] = v;
			} 	
		}
	}
}
```