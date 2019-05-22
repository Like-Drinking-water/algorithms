#include <stdio.h>
#include <stdlib.h>

/*************************************
���⣺ʲôλ�÷���ը����������������
��ը����Ҫ�ܹ����ʹ�� # ��ʾǽ, G 
��ʾ����, . ��ʾ�յأ�ֻ�пյؿ��Է���
ը����ը�����ܴ���ǽ 
�����ʹ�ù���������� 
*************************************/
typedef struct QNote {
	//������ 
	int x;
	//������
	int y; 
} QNote; 

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

int main(void) {
	//���� 
	QNote *q;
	//��ͼ
	char **map;
	//��־ 
	int **book;
	//�������� ��ͼ��С ��� ���е������յ� 
	int i, j, n, m, startx, starty, head, tail, tmpx, tmpy;
	//���ֵ ĳ�����������ĵ������� ���ֵ���ڵ����� 
	int max, sum, x, y; 
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
	//�ж����λ���Ƿ�������ȷ 
	if (map[startx][starty] == '#' || map[startx][starty] == 'G') {
		printf("���ܽ�ը���˷�����ǽ����˴���");
		return 0;
	}
	//��ʼ������ 
	head = 0;
	tail = 0; 
	//�����з���ռ� 
	q = (QNote *)malloc(n * m * sizeof(QNote));
	//����㿪ʼ����
	book[startx][starty] = 1;
	q[tail].x = startx;
	q[tail].y = starty;
	tail++;
	max = getSum(startx, starty, map);
	x = startx;
	y = starty; 
	//��ʼ�����������
	while (head < tail) {
		for (i = 0; i < 4; i++) {
	 		//���Խ�����һ�� 
			tmpx = q[head].x + next[i][0];
			tmpy = q[head].y + next[i][1];
			//�ж��Ƿ�Խ��
			if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
				continue;
			} 
			//�ж��Ƿ��ǿյغ��Ƿ��Ѿ��߹�
			if (map[tmpx][tmpy] == '.' && book[tmpx][tmpy] == 0) {
				//������ӵ������в���־�Ѿ��� 
				book[tmpx][tmpy] = 1;
				q[tail].x = tmpx;
				q[tail].y = tmpy;
				tail++;
				//��ȡ�õ���������ĵ������� 
				sum = getSum(tmpx, tmpy, map);
				if (sum > max) { 
					x = tmpx;
					y = tmpy;
					max = sum;
				}
			} 
		} 
		//������һ�ι���������� 
		head++;
	} 
	printf("�ڵ� (%d, %d) ������������ %d ������", x, y, max); 
	return 0;
}

