# 队列
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


