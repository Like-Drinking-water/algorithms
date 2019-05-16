#include <stdio.h>
#include <stdlib.h>

/***************************************
问题：现有 m 跟火柴，要摆成 A + B = C 的
形式，已知：
1.加号与等号各用 2 根火柴
2.0-9分别用 6, 2, 5, 5, 4, 5, 6, 3, 7, 6
根火柴
3.所有的火柴都必须用上
解决：用枚举法 
****************************************/ 
/**
* 计算一个数所需要用到的火柴数量
* @Param num 要计算使用火柴数量的数字 
* @Return 返回这个数所用到的火柴数量 
*/
int MatchNum(int num) {
	//用来存放 0 - 9 每个数所用到的火柴数 
	int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; 
	//用来计算一共用了多少根火柴 
	int sum = 0;
	//不符合 
	if (num < 0) {
		return -1;
	}
	do {
		sum += a[num % 10];
		num /= 10;
	} while (num != 0);
	return sum;
} 

/**
* 计算a b能取的最大的数 
*/
int maxNum(int m) {
	int i = (m - 4) / 4 - 1;
	int num = 1;
	for (;i > 0; i--) {
		num *= 10;
		num++;
	}
	return num;
}

int main(void) {
	int a, b, c, m;
	//a b能取的最大的数 
	int max; 
	//表示一共有多少个等式 
	int sum;
	//实际数可以用到的火柴数量 
	int real;
	//获取火柴的数量
	scanf("%d", &m);
	real = m - 4; 
	//计算出最大的数
	max = maxNum(m);
	for (a = 0; a < max; a++) {
		for (b = 0; b < max; b++) {
			c = a + b;
			if (MatchNum(a) + MatchNum(b) + MatchNum(c) == real) {
				sum++;
				printf("%d + %d = %d\n", a, b, c);
			}
		} 
	}
	printf("Have : %d", sum);
	return 0;
}
