#include <stdio.h>
#include <stdlib.h>

/************************************************
���⣺��һ����ά��ͼ�У������·���ߵ��յ㣬���� 0
��ʾ�յأ�1 ��ʾ�ϰ���
�����ʹ�ù���������� 
************************************************/ 

typedef struct QNode {
	//������ 
	int x;
	//������ 
	int y;
	//���ڵ���ڶ����еı��
	int father;
	//�Ѿ��ߵĲ���
	int step; 
}QNode; 

typedef struct Path {
	//������ 
	int x;
	//������ 
	int y;
}Path;


int main(void) {
	//���������ͼ�Լ���� 
	int **map, **book;
	Path *path; 
	//������Ƕ��е�������յ� 
	int head, tail; 
	//��������ڵ� 
	QNode *q;
	//�������� ��ͼ�Ĵ�С ��� �յ� ��ʱλ�� �����յ�ı�־ 
	int i, j, n, m, startx, starty, endx, endy, tmpx, tmpy, flag; 
	//��һ�������ߵĵط� 
	int next[4][2] = {
						{0, 1}, //������ 
						{1, 0}, //������ 
						{0, -1}, //������ 
						{-1, 0} //������ 
					}; 
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
	//�����з���ռ�
	q = (QNode *)malloc(n * m * sizeof(QNode));
	//��ʼ������
	head = 0;
	tail = 0;
	//����㿪ʼ����
	//������в������ 
	book[startx][starty] = 1;
	q[tail].x = startx;
	q[tail].x = starty;
	q[tail].father = -1;
	q[tail].step = 0;
	tail++;
	//��ʼ�������յ�ı��
	flag = 0; 
	while (head < tail) {
		for (i = 0; i < 4; i++) {
			tmpx = q[head].x + next[i][0];
			tmpy = q[head].y + next[i][1];
			//�ж��Ƿ�Խ�� ���Խ�����������ǰ�� 
			if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
				continue;
			}
			//�ж��Ƿ��Ѿ��߹�����һ���ǲ��ǿյ� 
			if (book[tmpx][tmpy] == 0 && map[tmpx][tmpy] == 0) {
				//��������Ѿ��߹� 
				book[tmpx][tmpy] = 1; 
				q[tail].x = tmpx;
				q[tail].y = tmpy;
				q[tail].father = head;
				//��ԭ���Ĳ����ϼ�һ 
				q[tail].step = q[head].step + 1;
				tail++;
			}
			if (tmpx == endx && tmpy == endy) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			break;
		}
		head++;
	} 
	//��ӡһ�����˶��ٲ�
	printf("%d\n", q[tail - 1].step);
	//�����ռ������·��
	path = (Path *)malloc((q[tail - 1].step + 1) * sizeof(Path));
	i = tail - 1;
	j = -1;
	//��·����ȡ�� path �� 
	while (i != -1) {
		j++;
		path[j].x = q[i].x;
		path[j].y = q[i].y;
		i = q[i].father;
	}
	//��ӡ·�� 
	while (j != -1) {
		printf("(%d, %d)",path[j].x, path[j].y); 
		if (j) {
			printf(" -> ");
		}
		j--;	
	}
	
	//��ӡ·�� 
	return 0;
}
