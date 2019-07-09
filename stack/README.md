# 栈
## 目录简介
* [PalindromeProblem](https://github.com/Like-Drinking-water/algorithms/tree/master/stack/PalindromeProblem) - 通过栈判断是否是回文
* [conversion](https://github.com/Like-Drinking-water/algorithms/tree/master/stack/conversion) - 进制转换
* [calculation](https://github.com/Like-Drinking-water/algorithms/tree/master/stack/calculation) - 表达式求值
* [hanoi](https://github.com/Like-Drinking-water/algorithms/tree/master/stack/hanoi) - hanoi塔问题
## 数据结构
``` c
typedef struct {
    //栈底指针
    ElementType *base;
    //栈顶指针
    ElementType *top;
    //已申请存放数据的空间大小
    int stackSize;
}
```


