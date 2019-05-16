#include <stdio.h>
#include <stdlib.h>

/*************************************
问题：什么位置放置炸弹可以消灭最多敌人
使用 # 表示墙, G 表示敌人, . 表示空地
只有空地可以放置炸弹，炸弹不能穿过墙 
解决：使用枚举 
*************************************/

int main(void) {
	//默认最大地图为 20 * 20 
	char a[20][20]; 
	//表示要设置的地图的大小 
	int n, m; 
	//表示炸弹的坐标 
	int y, x;
	//辅助变量 
	int i, j;
	//用于统计消灭敌人的个数
	int sum;
	//用于记录消灭敌人最多的个数以及位置坐标 
	int max = 0, xm, ym; 
	//设置地图的大小 
	scanf("%d %d", &n, &m); 
	//初始化地图 
	for (i = 0; i < n; i++) {
		scanf("%s", &a[i]);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j] == '.') {
				sum = 0;
				y = i, x = j;
				//往四个方向进行统计消灭敌人的数量 
				while (a[y][x] != '#') {
					if (a[y][x] == 'G') {
						sum++;
					}
					x--;
				}
				y = i, x = j;
				while (a[y][x] != '#') {
					if (a[y][x] == 'G') {
						sum++;
					}
					y--;
				}
				y = i, x = j;
				while (a[y][x] != '#') {
					if (a[y][x] == 'G') {
						sum++;
					}
					x++;
				}
				y = i, x = j;
				while (a[y][x] != '#') {
					if (a[y][x] == 'G') {
						sum++;
					}
					y++;
				}
				if (sum > max) {
					max = sum;
					ym = n - i;
					xm = j + 1;
				} 
			}
		}
	} 
	printf("将炸弹放置在(%d, %d)处，消灭最多 %d 个敌人", xm, ym, max);
	return 0;
}

