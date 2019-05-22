#include <stdio.h>
#include <stdlib.h>

/******************************************************** 
���⣺����һ�ŵ�ͼ����ͼ�� 0 ��ʾ�����������ֱ�ʾ½�أ�
ͨ����½�ĵ������½��������(�����ٸ�����)��������������
�ĵ��ʾͬһ������
�����ͨ������������ؽ�� 
*********************************************************/
//��½λ�õ���� 
int area = 0;
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
	int i, tmpx, tmpy;
	//��һ�������ߵĵط� 
	int next[4][2] = {
						{0, 1}, //������ 
						{1, 0}, //������ 
						{0, -1}, //������ 
						{-1, 0} //������ 
					}; 
	area++;
	map[x][y] = color;
	for (i = 0; i < 4; i++) {
		//��һ�������ߵ�λ�� 
		tmpx = x + next[i][0];
		tmpy = y + next[i][1];
		//�ж��Ƿ�Խ��
		if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
			continue;
		} 
		//�ж���һ���Ƿ���½�ض��һ�û�о��� 
		if (map[tmpx][tmpy] && book[tmpx][tmpy] == 0) {
			//��Ǿ���
			book[tmpx][tmpy] = 1;
			//������һ��
			dfs(tmpx, tmpy, color, map, book); 
		} 
	}
	return;
} 

int main(void) {
	//��½�� 
	int landingx, landingy;
	//��ͼ�Լ���־
	int **map, **book; 
	//�������� 
	int i, j;
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
	//��ȡ��½��
	scanf("%d %d", &landingx, &landingy);
	//�ж���½�ص��Ƿ��Ǻ���
	if (!map[landingx][landingy]) {
		printf("����������ˣ�");
		return 0;
	} 
	//��ʼ����������� 
	book[landingx][landingy] = 1;
	dfs(landingx, landingy, -1, map, book);
	//չʾ��� 
	printf("%d\n", area);
	//չʾȾɫ��ĵ�ͼ
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d\t", map[i][j]);
		}
		printf("\n"); 
	}
	return 0;
}
