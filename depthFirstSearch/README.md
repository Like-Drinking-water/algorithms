# 深度优先搜索
在这个算法当中，将每个数放的位置看成一个盒子，将要放到数看成一张牌  
将牌放到盒子中以实现排列  
约定好每到一个盒子前都先放一号牌，再放二号牌依此类推  
## 目录简介
* [fillNumber](https://github.com/Like-Drinking-water/algorithms/tree/master/depthFirstSearch/fillNumber) - 通过深度优先搜索算法填数字使等式成立
* [findInMap](https://github.com/Like-Drinking-water/algorithms/tree/master/depthFirstSearch/findInMap) - 通过深度优先搜索算法找到从起点到终点的最短路径
* [fullPermutation](https://github.com/Like-Drinking-water/algorithms/tree/master/depthFirstSearch/fullPermutation) - 通过深度优先搜索完成全排列
* [Bomberman](https://github.com/Like-Drinking-water/algorithms/tree/master/depthFirstSearch/Bomberman) - 通过深度优先搜索算法找到炸弹人能走的路径并求出能消灭最多敌人的点
## 关键代码
设有 n 个盒子  
每一次到达新盒子前，都判断是不是到达 n + 1 个盒子  
如果到达则说明前面盒子的都放置完成， 即完成了一次排列
``` c
//因为数组下标是从 0 开始，所以 n + 1 个盒子在下标 n 处
if (step == n) {
    //对盒子进行操作
    dosomething
    //操作完后要回到上一个盒子
    return;
}
```
如果没有到达最后一个盒子则要进行放数炒作
``` c
//假设往盒子中放的数为 1 - n 的数
//book 用来标记手上有没有这张牌
//有的话为 1, 没有为 0 
for (i = 1; i <= n; i++) {
    //手上有牌 要进行放置
    if (book[i] == 1) {
        //用 a 来表示盒子
        //step 表示当前位于哪一个盒子
        //将牌放到盒子中并取消标记
        a[step] = i;
        book[i] = 0;
        //放完后进入下个盒子
        //通过递归调用
        dfs(step + 1, n, a, book);
        //回到原来的盒子后要将盒子中的手牌拿回来
        book[i] = 1;
    }
}
return;
```

