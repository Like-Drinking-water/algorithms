#include <stdio.h>
#include <stdlib.h>

/******************************************************** 
���⣺����һ�ŵ�ͼ����ͼ�� 0 ��ʾ�����������ֱ�ʾ½�أ�
����һ���ж��ٸ����죬�������������ĵ��ʾͬһ������
�����ͨ������������ؽ�� 
*********************************************************/

typedef struct QNote {
	//������ 
	int x;
	//������ 
	int y;
} QNote; 

int main(void) {
	//���������
	int numberOfLand = 0; 
	//���� 
	QNote *q; 
	int head, tail; 
	//��ͼ�Լ���� 
	int **map, **book;
	//�������������һ�������ߵ�λ��
	int tmpx, tmpy; 
	//��������
	int i, j, k; 
	//��ͼ�Ĵ�С
	int n, m; 
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
	//��ʼ����
	q = (QNote *)malloc(sizeof(QNote) * n * m);
	head = 0;
	tail = 0;
	//ö�ٵ�ͼ�ϵĵ�
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			//ö�ٵ��ĵ���½����û���߹�
			//˵����һ���µĵ��� 
			if (map[i][j] && book[i][j] == 0) {
				//�����������һ
				numberOfLand++;
				//�����������в���־�Ѿ����� 
				q[tail].x = i;
				q[tail].y = j;
				tail++;
				map[i][j] = numberOfLand;
				book[i][j] = 1; 
				//���й����������
				while (head < tail) {
					for (k = 0; k < 4; k++) {
						//��һ��������λ�� 
						tmpx = q[head].x + next[k][0];
						tmpy = q[head].y + next[k][1];
						//�ж��Ƿ�Խ��
						if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) {
							continue;
						} 
						if (map[tmpx][tmpy] && book[tmpx][tmpy] == 0) {
							//����Ѿ��߹� 
							book[tmpx][tmpy] = 1;
							//�������Ⱦɫ
							map[tmpx][tmpy] = numberOfLand;
							//��ӵ������� 
							q[tail].x = tmpx;
							q[tail].y = tmpy;
							tail++;
						}
					}
					head++;
				}
				//��ԭ���� 
				head = 0;
				tail = 0; 
			}
		}
	} 
	//��ӡ���������
	printf("%d\n", numberOfLand);
	//��ӡȾɫ��ĵ�ͼ 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%2d", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
