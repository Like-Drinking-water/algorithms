#include <stdio.h>
#include <stdlib.h>

/******************************************************** 
���⣺����һ�ŵ�ͼ����ͼ�� 0 ��ʾ�����������ֱ�ʾ½�أ�
����һ���ж��ٸ����죬�������������ĵ��ʾͬһ������
�����ͨ������������ؽ�� 
*********************************************************/

//��ͼ�Ĵ�С 
int n, m; 

/**
* �����������
* @Param x ������
* @Param y ������
* @Param color ҪȾ����ɫ 
* @Param map ��ͼ
* @Param book ��� 
*/
void dfs(int x, int y, int color, int **map, int **book) {
	int i;
	int tmpx, tmpy; 
	//��һ�������ߵĵط� 
	int next[4][2] = {
						{0, 1}, //������ 
						{1, 0}, //������ 
						{0, -1}, //������ 
						{-1, 0} //������ 
					}; 
	//Ⱦɫ 
	map[x][y] = color;
	for (i = 0; i < 4; i++) {
		//��һ������Ҫ�ߵĵط� 
		tmpx = x + next[i][0];
		tmpy = y + next[i][1];
		//�ж���һ���Ƿ�Խ�� 
		if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
			continue;
		} 
		//�ж��Ƿ���½�����Ƿ��߹�
		if (map[tmpx][tmpy] && book[tmpx][tmpy] == 0) {
			//����Ѿ��߹� 
			book[tmpx][tmpy] = 1;
			//������һ��
			dfs(tmpx, tmpy, color, map, book); 
		} 
	}
	return;
} 

int main(void) {
	int numberOfLand = 0;
	//��������
	int i, j; 
	//��ͼ�Լ���� 
	int **map, **book;
	//�����ͼ�Ĵ�С 
	scanf("%d %d", &n, &m);
	//��̬������ά�������ͼʹ�� 
	map =(int **)malloc(sizeof(int *) * n);  
    for(i = 0; i < n; i++) {
    	map[i] = (int *)malloc(sizeof(int) * m); 
	}
	//��ȡ��ͼ
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	//��̬������ά�����·�����ʹ�� 
	book =(int **)malloc(sizeof(int *) * n);  
    for(i = 0; i < n; i++) {
    	book[i] = (int *)malloc(sizeof(int) * m); 
	}
    //��ʼ����� 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			book[i][j] = 0;
		}
	}
	//ö�ٵ�ͼ�ϵ�λ�� 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			//���û��ȥ�����ط��ҵ�ͼ�����ط���½��
			//�������һ���µĵ��� 
			if (map[i][j] && book[i][j] == 0) {
				numberOfLand++;
				dfs(i, j, numberOfLand, map, book); 
			}
		}
	}
	//��ӡ��������� 
	printf("%d\n", numberOfLand);
	//��Ⱦɫ��ĵ��� 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%2d", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
