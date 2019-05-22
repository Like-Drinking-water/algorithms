#include <stdio.h>
#include <stdlib.h>

/******************************************************** 
���⣺����һ�ŵ�ͼ����ͼ�� 0 ��ʾ�����������ֱ�ʾ½�أ�
ͨ����½�ĵ������½��������(�����ٸ�����)��������������
�ĵ��ʾͬһ������
�����ͨ������������ؽ�� 
*********************************************************/
//��ͼ�Ĵ�С 
#define N 10
#define M 10 
#define AREA N * M

typedef struct QNote {
	int x;
	int y;
} QNote; 

int main(void) {
	//��ͼ 
	int map[N][M];
	//��־ 
	int book[N][M];
	QNote q[AREA]; 
	//�������� ��½������ ����ͷָ�� ½����� 
	int i, j, landingx, landingy, tmpx, tmpy, head, tail, area = 0;
	//��һ�������ߵĵط� 
	int next[4][2] = {
						{0, 1}, //������ 
						{1, 0}, //������ 
						{0, -1}, //������ 
						{-1, 0} //������ 
					}; 
	//������½��λ��
	scanf("%d %d", &landingx, &landingy);
	//��ȡ��ͼ
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	} 
	//�ж���½�ص��Ƿ��Ǻ���
	if (!map[landingx][landingy]) {
		printf("����������ˣ�");
		return 0;
	} 
	//��ʼ����־ 
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			book[i][j] = 0; 
		}
	} 
	//��ʼ������
	head = 0;
	tail = 0;
	q[tail].x = landingx;
	q[tail].y = landingy;
	//��־��½���Լ����� 
	book[landingx][landingy] = 1;
	tail++;
	area++; 
	//��ʼ����������� 
	while (head < tail) {
		for (i = 0; i < 4; i++) {
			//��һ�������ߵ�λ�� 
			tmpx = q[head].x + next[i][0];
			tmpy = q[head].y + next[i][1];
			//�ж��Ƿ�Խ��
			if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M) {
				continue;
			}
			//�ж��Ƿ���½��
			if (map[tmpx][tmpy] && book[tmpx][tmpy] == 0) {
				//��־�Ѿ��߹�
				book[tmpx][tmpy] = 1;
				q[tail].x = tmpx;
				q[tail].y = tmpy;
				tail++;
				area++;
			}
		}
		head++;
	}
	printf("%d", area);
	return 0;
}
