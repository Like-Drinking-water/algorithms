#include <stdio.h>
#include <stdlib.h>

/************************************************
���⣺��һ����ά��ͼ�У������·���ߵ��յ㣬���� 0
��ʾ�յأ�1 ��ʾ�ϰ���
�����ʹ������������� 
************************************************/ 
//������¼���·�� 
int min = 2147483647; 
//������ʾ��ͼ�Ĵ�С
int n, m; 

/**
* ��������������� �����յ�
* @Param startx ��ʼ������
* @Param starty ��ʼ������
* @Param endx �յ�������
* @Param endy �յ�������
* @Param step �Ѿ��ߵĲ���
* @Param map ��ͼ
* @Param book �������·�� 
*/
void dfs(int startx, int starty, int endx, int endy, int step, int **map, int **book) {
	int i;
	int tmpx, tmpy; 
	int next[4][2] = {
						{0, 1}, //������ 
						{1, 0}, //������ 
						{0, -1}, //������ 
						{-1, 0} //������ 
					}; 
	//�ж��Ƿ��Ѿ������յ� 
	if (startx == endx && starty == endy) {
		//�����յ���·�����Ѿ��߹���·������ 
		if (step < min) {
			min = step;
		}
		return;
	}
	for (i = 0; i < 4; i++) {
		//ȷ����һ����λ�� 
		tmpx = startx + next[i][0];
		tmpy = starty + next[i][1];
		//�ж��Ƿ�Խ�� ���Խ�����������ǰ�� 
		if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
			continue;
		}
		//�ж��Ƿ��Ѿ��߹�����һ���ǲ��ǿյ� 
		if (book[tmpx][tmpy] == 0 && map[tmpx][tmpy] == 0) {
			//��������Ѿ��߹� 
			book[tmpx][tmpy] = 1; 
			//������һ���� 
			dfs(tmpx, tmpy, endx, endy, step + 1, map, book);
			//������ȡ�����
			book[tmpx][tmpy] = 0; 
		}
		
	}
	return;
}

int main() {
	//������ʾ��ͼ�ͱ���߹���·�� 
	int **map, **book;
	//�����յ����� 
	int startx, starty, endx, endy; 
	int i, j;
	//�����ͼ�Ĵ�С 
	scanf("%d %d", &n, &m);
	//��̬������ά�������ͼʹ�� 
	map =(int **)malloc(sizeof(int*) * n);  
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
	book =(int **)malloc(sizeof(int*) * n);  
    for(i = 0; i < n; i++) {
    	book[i] = (int *)malloc(sizeof(int) * m); 
	} 
    //��ʼ����� 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			book[i][j] = 0;
		}
	}
	//��ȡ������յ� 
	scanf("%d %d %d %d", &startx, &starty, &endx, &endy);
	//����㿪ʼ����
	//�������Ѿ��߹� 
	book[startx][starty] = 1; 
	dfs(startx, starty, endx, endy, 0, map, book);
	//��ӡ���·���Ĵ�С
	printf("%d", min); 
	return 0;
}

