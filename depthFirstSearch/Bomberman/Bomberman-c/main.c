#include <stdio.h>
#include <stdlib.h>

/*************************************
���⣺ʲôλ�÷���ը����������������
��ը����Ҫ�ܹ����ʹ�� # ��ʾǽ, G 
��ʾ����, . ��ʾ�յأ�ֻ�пյؿ��Է���
ը����ը�����ܴ���ǽ 
�����ʹ�ù���������� 
*************************************/
//���ֵ�Լ����ֵ������ 
int max = 0, x, y;
//��ͼ�Ĵ�С
int m, n; 

/**
* ��ȡ��ͼ��ĳ������������˵ĸ���
* @Param x ������
* @Param y ������
* @Param map ��ͼ
* @Return ������˵����� 
*/
int getSum(int x, int y, char **map) {
	int sum, i, j;
	sum = 0;
	//������ 
	i = x, j = y;
	while (map[i][j] != '#') {
		i++;
		if (map[i][j] == 'G') {
			sum++;
		} 
	}
	//������ 
	i = x, j = y;
	while (map[i][j] != '#') {
		i++;
		if (map[i][j] == 'G') {
			sum++;
		} 
	}
	//������ 
	i = x, j = y;
	while (map[i][j] != '#') {
		j++;
		if (map[i][j] == 'G') {
			sum++;
		} 
	}
	//������ 
	i = x, j = y;
	while (map[i][j] != '#') {
		j--;
		if (map[i][j] == 'G') {
			sum++;
		} 
	}
	return sum; 
}

void dfs(int startx, int starty, char **map, int **book) {
	int sum, i, j, tmpx, tmpy;
	//��һ�������ߵĵط� 
	int next[4][2] = {
						{0, 1}, //������ 
						{1, 0}, //������ 
						{0, -1}, //������ 
						{-1, 0} //������ 
					}; 
	//��ȡ�õ��ڵ�ͼ��������ĵ��˵����� 
	sum = getSum(startx, starty, map);
	if (sum > max) {
		max = sum;
		x = startx;
		y = starty;
	}
	for (i = 0; i < 4; i++) {
		//��һ�������ߵ����� 
		tmpx = startx + next[i][0];
		tmpy = starty + next[i][1];
		//�ж��Ƿ�Խ��
		if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
			continue;
		}
		//�ж��Ƿ�յ�
		if (map[tmpx][tmpy] == '.' && book[tmpx][tmpy] == 0) {
			book[tmpx][tmpy] = 1;
			dfs(tmpx, tmpy, map, book);
		} 
	} 
	return;
}

int main(void) {
	//��ͼ 
	char **map;
	//��� 
	int **book;
	//�������� 
	int i, j, startx, starty; 
	//�����ͼ�Ĵ�С 
	scanf("%d %d", &n, &m);
	//��̬������ά�������ͼʹ�� 
	map =(char **)malloc(sizeof(char *) * n);  
    for(i = 0; i < n; i++) {
    	map[i] = (char *)malloc(sizeof(char) * m); 
	}
	//��ȡ��ͼ
	for (i = 0; i < n; i++) {
		scanf("%s", map[i]);
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
	//��ȡ���
	scanf("%d %d", &startx, &starty);
	//����㿪ʼ��������������� 
	dfs(startx, starty, map, book);
	//��ӡ��� 
	printf("�ڵ� (%d, %d) ������������ %d ������", x, y, max); 
	return 0;
}
