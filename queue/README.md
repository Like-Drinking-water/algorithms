# 队列
## 目录简介
* [DecryptQQProblem](https://github.com/Like-Drinking-water/algorithms/tree/master/queue/DecryptQQProblem) - 利用队列对 QQ 账号进行解密
* [DecryptQQProblem-struct](https://github.com/Like-Drinking-water/algorithms/tree/master/queue/DecryptQQProblem-struct) - 将队列封装成结构体
* [LinkQueue](https://github.com/Like-Drinking-water/algorithms/tree/master/queue/LinkQueue) - 链队列
* [CircularQueue](https://github.com/Like-Drinking-water/algorithms/tree/master/queue/CircularQueue) - 循环队列
## 数据结构
### 链队列
``` c
typedef struct QNode{
    //存放数据
    ElementType date;
    //指向下一个节点
    struct QNode *next;
}QNode;
typedef struct {
    //队头指针
    QNode *head;
    //队尾指针
    QNode *tail;
}LinkedQueue;
```
### 循环队列
``` c
typedef struct {
	ElemType *base;
	int front;
	int rear;
} CircularQueue;


