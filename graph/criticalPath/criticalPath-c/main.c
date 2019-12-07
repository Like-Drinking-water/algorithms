#include <stdio.h>
#include <stdlib.h>

/* �ؼ�·�� */

#define MAX_VERTEX_NUM 30
//����ͼ 
#define Digraph 1 
//����ͼ
#define Undigraph 0 
#define OVERFLOW -1
#define STACK_INIT_SIZE 30
#define STACKINCREMENT 10
#define ERROR -1
#define OK 1

//���翪ʼʱ�� 
int *ve;
//����ʼʱ��
int *vl; 

typedef int InfoType; 
typedef int VertexType; 

typedef struct {
	int start;
	int end;
	int dut;
}Graph;

typedef struct ArcNode {
	int adjvex;     //�û�ָ��Ķ����λ�� 
	struct ArcNode *nextarc; //ָ����һ������ָ��
	InfoType info; //�û������Ϣ��ָ�� 
}ArcNode; 

typedef struct VNode {
	VertexType data; //������Ϣ 
	ArcNode *firstarc; //ָ���һ�������ö���Ļ���ָ�� 
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum; //ͼ�ĵ�ǰ�������ͻ���
	int kind;  //ͼ������ 
}ALGraph;

typedef struct {
	int *base;
	int *top;
	int stackSize;
} Stack; 

void initStack(Stack *s) {
	s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!s->base) {
		//�ڴ����ʧ�� 
		exit(OVERFLOW);
	}
	s->top = s->base; 
	s->stackSize = STACK_INIT_SIZE;
}

int push(Stack *s, int e) {
	if (s->top - s->base >= s->stackSize) {
		s->base = (int *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(int));
		if (!s->base) {
			//�ڴ����ʧ�� 
			exit(OVERFLOW);
		}
		s->top = s->base + s->stackSize;
		s->stackSize += STACKINCREMENT;
	}
	*(s->top) = e;
	s->top++;
}

int pop(Stack *s, int *e) {
	if (s->base == s->top) {
		return ERROR;
	}
	s->top--;
	*e = *(s->top);
	return OK;
}

int stackEmpty(Stack s) {
	return (s.base == s.top);
}

int createGraph(ALGraph *graph, Graph **g, int vexnum, int arcnum, int kind) {
	int i, j;
	ArcNode *tmp;
	ArcNode *last;
	graph->vexnum = vexnum;
	//��ʼ��ͷ��� 
	for (i = 0; i < vexnum; i++) {
		graph->vertices[i].firstarc = NULL;
		graph->vertices[i].data = i;
	}
	for (i = 0; i < arcnum; i++) {
		tmp = (ArcNode *)malloc(sizeof(ArcNode));
		//�޷������ڴ� 
		if (!tmp) {
			exit(OVERFLOW);
		}
		tmp->adjvex = g[i]->end;
		tmp->nextarc = NULL;
		tmp->info = g[i]->dut;
		last = graph->vertices[g[i]->start].firstarc; 
		if (last != NULL) {
			while (1) {
				//��last��û����һ������ 
				if(last->nextarc == NULL) {
					break;
				}
				else {
					last = last->nextarc;
				}
			}
			last->nextarc = tmp; 
		} 
		else {
			graph->vertices[g[i]->start].firstarc = tmp;
		}
	} 
	graph->arcnum = arcnum;
	graph->kind = kind;
	return OK;
}

void findInDegree(ALGraph *graph, int *indegree) {
	int i;
	ArcNode *tmp;
	//��ʼ������ 
	for (i = 0; i < graph->vexnum; i++) {
		indegree[i] = 0; 
	} 
	for (i = 0; i < graph->vexnum; i++) {
		tmp = graph->vertices[i].firstarc;
		while(tmp != NULL) {
			indegree[tmp->adjvex]++;
			tmp = tmp->nextarc;
		}
	}
}

int topologicalOrder(ALGraph *graph, Stack *t) {
	int indegree[MAX_VERTEX_NUM];
	Stack *s;
	int i, j;
	ArcNode *tmp;
	//��¼��������� 
	int count;
	
	s = (Stack *)malloc(sizeof(Stack));
	ve = (int *)malloc(sizeof(int) * graph->vexnum);
	//�ڴ����ʧ�� 
	if (!s && !ve) {
		exit(OVERFLOW);
	}
	findInDegree(graph, indegree);
	initStack(s);
	initStack(t);
	//��ʼ�����翪ʼʱ��
	for (i = 0; i < graph->vexnum; i++) {
		ve[i] = 0;
	} 
	for (i = 0; i < graph->vexnum; i++) {
		if (!indegree[i]) {
			push(s, i);
		}
	} 
	count = 0;
	while (!stackEmpty(*s)) {
		pop(s, &i);
		push(t, i);
		//���� 
		count++;
		for (tmp = graph->vertices[i].firstarc; tmp; tmp = tmp->nextarc) {
			j = tmp->adjvex;
			indegree[j]--;
			if (!indegree[j]) {
				push(s, j);
			}
			if (ve[i] + tmp->info > ve[j]) {
				ve[j] = ve[i] + tmp->info;
			}
		} 
	}
	//�л� 
	if (count < graph->vexnum) {
		return ERROR;
	}
	else {
		return OK;
	} 
}

int criticalPath(ALGraph *graph) {
	int i, j;
	Stack *t;
	ArcNode *tmp;
	int dut;
	char tag;
	int ee, el;
	t = (Stack *)malloc(sizeof(Stack));
	if (!topologicalOrder(graph, t)) {
		return ERROR;
	}
	//��ʼ������ʼʱ�� 
	vl = (int *)malloc(sizeof(int) * graph->vexnum);
	for (i = 0; i < graph->vexnum; i++) {
		vl[i] = ve[graph->vexnum - 1];
	}
	while (!stackEmpty(*t)) {
		pop(t, &i);
		for (tmp = graph->vertices[i].firstarc; tmp; tmp = tmp->nextarc) {
			j = tmp->adjvex;
			dut = tmp->info;	
			if (vl[j] - dut < vl[i]) {
				vl[i] = vl[j] - dut;
			}
		}
	} 
	//��ӡ�ؼ�� 
	for (i = 0; i < graph->vexnum; ++i) {
		for (tmp = graph->vertices[i].firstarc; tmp; tmp = tmp->nextarc) {
			j = tmp->adjvex;
			dut = tmp->info;
			ee = ve[i];
			el = vl[j] - dut; 
			tag = (ee == el) ? '*' : ' ';
			printf("%d --%d--> %d %c\n", i, dut, j, tag);
		} 
	}
}

int main(int argc, char *argv[]) {
	int i;
	Graph **g;
	ALGraph *graph;
	g = (Graph **)malloc(sizeof(Graph *) * 8);
	for (i = 0; i < 8; i++) {
		g[i] = (Graph *)malloc(sizeof(Graph)); 
	}
	g[0]->start = 0;
	g[0]->end = 1;
	g[0]->dut = 3;
	g[1]->start = 0;
	g[1]->end = 2;
	g[1]->dut = 2;
	g[2]->start = 1;
	g[2]->end = 3;
	g[2]->dut = 2;
	g[3]->start = 1;
	g[3]->end = 4;
	g[3]->dut = 3;
	g[4]->start = 2;
	g[4]->end = 3;
	g[4]->dut = 4;
	g[5]->start = 2;
	g[5]->end = 5;
	g[5]->dut = 3;
	g[6]->start = 3;
	g[6]->end = 5;
	g[6]->dut = 2;
	g[7]->start = 4;
	g[7]->end = 5;
	g[7]->dut = 1;
	graph = (ALGraph *)malloc(sizeof(ALGraph));
	createGraph(graph, g, 6, 8, Digraph);
	criticalPath(graph);
	return 0;
}
