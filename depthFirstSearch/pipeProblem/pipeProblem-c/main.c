#include <stdio.h>
#include <stdlib.h>

/******************************************************
���⣺ˮ���������⣬ͨ��ת��ˮ��ʹˮ�ܹ��������������
ˮ�ܷ�Ϊ��ܸ�ֱ��
��     ������ ������     ��           �� 
������ ��         �� ������ ������    ��     �� 
  1      2      3      4      5       6      0(��ʾ�ϰ�)
 ��ͷ����ʾˮ�������� ֻ��ʾˮ�ܵ���״
���������������� 
*******************************************************/
typedef struct Node {
	int x;
	int y;
} Node; 
//��ͼ�Ĵ�С 
int n, m;
//�ҵ����ڵı�־
int flag = 0; 
//�ñ���·�� 
Node *node;
//���һ��Ԫ�ص�λ�� 
int top = 0;
/**
* �����������
* @Param x ������
* @Param y ������
* @Param front ˮ���ķ���(1 ��ʾ���;2 ��ʾ�ұ�;3 ��ʾ�ϱ�;4 ��ʾ�±�) 
* @Param map ��ͼ
* @Param book ������ߵ�·�� 
*/
void dfs(int x, int y, int front, int **map, int **book) {
	int i;
	if (x == n - 1 && y == m) {
		flag = 1;
		for (i = 0; i < top; i++) {
			printf("(%d, %d) ", node[i].x, node[i].y);
		}
		return;
	} 
	//�ж��Ƿ�Խ��
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return;
	} 
	//�ж����ˮ���Ƿ���·�����Ѿ��߹� 
	if (book[x][y] == 1) {
		return;
	}
	//��Ǹõ��Ѿ��߹� 
	book[x][y] = 1;
	node[top].x = x;
	node[top].y = y;
	top++;
	//��ʾ��� 
	if (map[x][y] >= 1 && map[x][y] <= 4) { 
		/* 
		//ˮ�ķ��������� 
		if (front == 1) {
			//ˮ�����±� 
			dfs(x + 1, y, 3, map, book); //3�Ź� 
			//ˮ�����ϱ�
			dfs(x - 1, y, 4, map, book); //4�Ź� 
		}
		//ˮ�ķ�����ұ��� 
		if (front == 2) {
			//ˮ�����±� 
			dfs(x + 1, y, 3, map, book); //2�Ź� 
			//ˮ�����ϱ� 
			dfs(x - 1, y, 4, map, book); //1�Ź� 
		}
		//ˮ�ķ�����ϱ��� 
		if (front == 3) {
			//ˮ������� 
			dfs(x, y - 1, 2, map, book); //4�Ź� 
			//ˮ�����ұ� 
			dfs(x, y + 1, 1, map, book); //1�Ź� 
		}
		//ˮ�ķ�����±��� 
		if (front == 4) {
			//ˮ������� 
			dfs(x, y - 1, 2, map, book); //3�Ź� 
			//ˮ�����ұ� 
			dfs(x, y + 1, 1, map, book); //2�Ź� 
		}
		*/ 
		//ˮ�ķ������߻��ұ��� 
		if (front == 1 || front == 2)  {
			//ˮ�����±� 
			dfs(x + 1, y, 3, map, book); //3�Ź� | 2�Ź� 
			//ˮ�����ϱ�
			dfs(x - 1, y, 4, map, book); //4�Ź� | 1�Ź� 
		}
		//ˮ�ķ�����ϱ߻��±��� 
		if (front == 3 || front == 4) {
			//ˮ������� 
			dfs(x, y - 1, 2, map, book); //4�Ź� | 3�Ź� 
			//ˮ�����ұ� 
			dfs(x, y + 1, 1, map, book); //1�Ź� | 2�Ź� 
		} 
	} 
	//��ʾֱ�� 
	if (map[x][y] == 5 || map[x][y] == 6) {
		//ˮ�ķ��������� 
		if (front == 1) {
			dfs(x, y + 1, 1, map, book); //5�Ź� 
		} 
		//ˮ�ķ�����ұ��� 
		if (front == 2) {
			dfs(x, y - 1, 2, map, book); //5�Ź� 
		} 
		//ˮ�ķ�����ϱ��� 
		if (front == 3) {
			dfs(x + 1, y, 3, map, book); //6�Ź� 
		} 
		//ˮ�ķ�����±߱��� 
		if (front == 4) {
			dfs(x - 1, y, 4, map, book); //6�Ź� 
		} 
	}
	//��һ��·������󽫱��ȡ�� 
	book[x][y] = 0;
	top--;
	return; 
} 

int main(void) {
	
	//��ͼ�Լ����߱�� 
	int **map, **book; 
	//�������� 
	int i, j; 
	//��ȡ��ͼ�Ĵ�С 
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
	//Ϊ·���ڵ㿪�ٿռ� 
	node = (Node *)malloc(sizeof(Node) * n * m);
	//��ʼ����������� 
	dfs(0, 0, 1, map, book); 
	if (!flag) {
		printf("û��һ��·���ܹ������ˮ��"); 
	}
	return 0;
}
