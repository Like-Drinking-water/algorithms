#include <stdio.h>
#include <stdlib.h>

/*********************************
问题：对 1 - n 进行全排列
解决：使用深度优先搜索算法 
*********************************/
/**
* 进行深度优先搜索
* @Param step 表示当前位于哪个盒子
* @Param n 表示有多少个数
* @Param a 表示盒子
* @Param book 表示手牌标记，1 表示有 0 表示没有 
*/ 
void dfs(int step, int n, int *a, int *book) {
	int i;
	//如果站到了最后一个盒子 
	//说明一次排列完成 
	if (step == n) {
		//将一次排列进行输出 
		for (i = 0; i < n; i++) {
			printf("%d", a[i]);
		} 
		printf("\n");
		return;
	}
	//按照 1 - n 的顺序放入盒子 
	for (i = 1; i <= n; i++) {
		//book[i] == 1 表示手中有牌 
		if (book[i] == 1) {
			//将 i 放入第 step 个盒子 
			a[step] = i;
			book[i] = 0;
			//到下一个盒子
			dfs(step + 1, n, a, book);
			//回到当前盒子再取回牌子 
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
	int *book 
	int i;
	book = (int *)malloc((n + 1) * sizeof(int));
	//初始化 book 中的值 
	for (i = 1; i <= n; i++) {
		book[i] = 1;
	}
	return book;
}

int main(void) {
	int *a, *book, n;
	//输入多少个值 
	scanf("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	//初始化 book 
	book = initBook(n);
	//从第 0 个盒子开始放
	dfs(0, n, a, book);
	return 0;
}
