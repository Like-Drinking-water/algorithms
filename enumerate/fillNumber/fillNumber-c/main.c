#include <stdio.h>
#include <stdlib.h>

/***************************************************
问题: _ _ _ + _ _ _ = _ _ _ 填上 1 - 9 的数使等式成立
每个数只能出现一次
解决: 使用枚举法 
****************************************************/

int main(void) {
	int a[10], i, sum, book[10], total = 0;
	for (a[1] = 1; a[1] <= 9; a[1]++) {
		for (a[2] = 1; a[2] <= 9; a[2]++) {
			for (a[3] = 1; a[3] <= 9; a[3]++) {
				for (a[4] = 1; a[4] <= 9; a[4]++) {
					for (a[5] = 1; a[5] <= 9; a[5]++) {
						for (a[6] = 1; a[6] <= 9; a[6]++) {
							for (a[7] = 1; a[7] <= 9; a[7]++) {
								for (a[8] = 1; a[8] <= 9; a[8]++) {
									for (a[9] = 1; a[9] <= 9; a[9]++) {
										//初始化标志 
										for (i = 1; i <= 9; i++) {
											book[i] = 0;
										}
										//添加标志 
										for (i = 1; i <= 9; i++) {
											book[a[i]] = 1;
										} 
										//计算一共使用了多少个数 
										sum = 0;
										for (i = 1; i <= 9; i++) {
											sum += book[i];
										} 
										if (sum == 9 && a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 +
										a[6] == a[7] * 100 + a[8] * 10 + a[9]) {
											total++;
											printf("%d%d%d+%d%d%d=%d%d%d\n", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	} 
	printf("Have : %d", total / 2);
	return 0;
}
