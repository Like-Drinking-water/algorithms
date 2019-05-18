#include <stdio.h>
#include <stdlib.h>

/**************************************************** 
问题: _ _ _ + _ _ _ = _ _ _ 填上 1 - 9 的数使等式成立
每个数只能出现一次
解决: 使用深度优先搜索 
*****************************************************/
//用来统计有多少个等式 
int total = 0;

/**
* 进行深度优先搜索
* @Param step 表示当前位于哪个盒子
* @Param n 表示有多少个数
* @Param a 表示盒子
* @Param book 表示手牌标记，1 表示有 0 表示没有 
*/ 
void dfs(int step, int n, int *a, int *book) {
	int i;
	//表示已经前面的盒子已经放完了 
	if (step == n) {
		//如果符合结果，将其输出 
		if (a[0] * 100 + a[1] * 10 + a[2] + a[3] * 100 + a[4] * 10 + a[5] ==
		a[6] * 100 + a[7] * 10 + a[8]) {
			printf("%d%d%d + %d%d%d = %d%d%d\n", a[0], a[1], a[2], a[3], a[4],
			a[5], a[6], a[7], a[8]);
			total++; 
		}
		//退回前一个盒子 
		return;
	}
	//往盒子中放置手牌 
	for (i = 1; i <= n; i++) {
		//手上有牌 
		if (book[i] == 1) {
			//将手牌放到盒子中 
			a[step] = i;
			book[i] = 0; 
			//接下去进入下一个盒子
			dfs(step + 1, n, a, book);
			//将手牌收回 
			book[i] = 1; 
		}
	}
	return; 
} 

/**
* 初始化 book
* @Param n 表示有多少个数需要标记 
* @Return 返回初始化完成的 book 
*/
int *initBook(int n) {
	int *book, i;
	book = (int *)malloc((n + 1) * sizeof(int));
	for (i = 1; i <= n; i++) {
		book[i] = 1;
	}
	return book;
}

int main(void) {
	int *a, *book;
	//初始化盒子与手牌 
	a = (int *)malloc(9 * sizeof(int));
	book = initBook(9);
	//从第一个盒子开始放置
	dfs(0, 9, a, book);
	printf("Have : %d", total >> 1);
	return 0;
}
