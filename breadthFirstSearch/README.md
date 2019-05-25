# 广度优先搜索 
深度优先搜索是每次往一个方向搜索，广度优先搜索是每次往所有的方向进行搜索
## 目录简介
* [findInMap](https://github.com/Like-Drinking-water/algorithms/tree/master/breadthFirstSearch/findInMap) - 通过广度优先搜索算法找到从起点到终点的最短路径
* [Bomberman](https://github.com/Like-Drinking-water/algorithms/tree/master/breadthFirstSearch/Bomberman) - 通过广度优先搜索算法找到炸弹人能走的路径并求出能消灭最多敌人的点
* [landingProblem](https://github.com/Like-Drinking-water/algorithms/tree/master/breadthFirstSearch/landingProblem) - 通过着陆的点判断着陆的岛屿面积
* [numberOfLand](https://github.com/Like-Drinking-water/algorithms/tree/master/breadthFirstSearch/numberOfLand) - 获取地图上一共有多少个岛屿
* [graphTraversal](https://github.com/Like-Drinking-water/algorithms/tree/master/breadthFirstSearch/graphTraversal) - 图的遍历
* [leastTransfer](https://github.com/Like-Drinking-water/algorithms/tree/master/breadthFirstSearch/leastTransfer) - 最少换乘
## 关键代码
深度优先搜索是一层一层搜寻  
首先先确定下一步能走地方
比如在方格中
``` c
int next[4][2] = {
	    {0, 1}, //向右走 
	    {1, 0}, //向下走 
	    {0, -1}, //向左走 
	    {-1, 0} //向上走 
			}; 
```
创建一个队列来存放下一步可以到达的点
``` c
typedef struct {
    //行坐标
    int x;
    //列坐标
    int y;
} QNode;
//根据需要的大小创建一个数组队列
QNode q[n][m];
int head = 0;
int tail = 0;
//或是创建链队列
typedef struct QNode {
    //行坐标
    int x;
    //列坐标
    int y;
    //下一个节点
    struct QNode *next;
} QNode;
typedef struct {
    //队头指针
    QNode *head;
    //队尾指针
    QNode *tail;
} LinkedQueue;
```
每一次搜索都枚举这些方向
``` c
//给到方格例子有 4 种方向
//所以这里是 4
while (head < tail) {
    for (i = 0; i < 4; i++) {
        tmpx = q[head].x + next[i][0];
        tmpy = q[head].y + next[i][1];
        //判断下一步是否越界
        if (...) {
            ...
        }
        //判断下一步是否可以走
        //下一步是否已经走过
        if (...) {
            ...
        }
    }
    //进入队列中的下一个元素进行搜索
    head++;
 }
```