# Floyd-Warshall 
Floyd-Warshall 算法不能解决带有“负权回路”
## 目录简介
* [shortestPath](https://github.com/Like-Drinking-water/algorithms/tree/master/Floyd-Warshall/shortestPath) - 使用 Floyd-Warshall 算法找到两点的最短路径
## 关键代码
``` c
for (k = 0; k < n; k++) {
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (graph[i][k] < inf && graph[k][j] < inf && graph[i][j] > graph[i][k] + graph[k][j]) {
				graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
}
```