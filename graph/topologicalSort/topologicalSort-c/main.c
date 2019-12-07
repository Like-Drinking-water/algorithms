#include <stdio.h>
#include <stdlib.h>

/*************************
********拓扑排序**********
**************************/

#define MAX_VERTEX_NUM 30
//有向图 
#define Digraph 1 
//无向图
#define Undigraph 0 
#define OVERFLOW -1
#define STACK_INIT_SIZE 30
#define STACKINCREMENT 10
#define ERROR -1
#define OK 1

typedef int InfoType; 
typedef int VertexType; 

typedef struct ArcNode {
	int adjvex;     //该弧指向的顶点的位置 
	struct ArcNode *nextarc; //指向下一条弧的指针
	InfoType *info; //该弧相关信息的指针 
}ArcNode; 

typedef struct VNode {
	VertexType data; //顶点信息 
	ArcNode *firstarc; //指向第一条依附该顶点的弧的指针 
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum; //图的当前顶点数和弧数
	int kind;  //图的类型 
}ALGraph;

typedef struct {
	int *base;
	int *top;
	int stackSize;
} Stack; 

void initStack(Stack *s) {
	s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!s->base) {
		//内存分配失败 
		exit(OVERFLOW);
	}
	s->top = s->base; 
	s->stackSize = STACK_INIT_SIZE;
}

int push(Stack *s, int e) {
	if (s->top - s->base >= s->stackSize) {
		s->base = (int *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(int));
		if (!s->base) {
			//内存分配失败 
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

int createGraph(ALGraph *graph, int **g, int vexnum, int kind) {
	int count;
	int i, j;
	ArcNode *tmp;
	ArcNode *last;
	//记录弧数 
	count = 0;
	graph->vexnum = vexnum;
	//初始化头结点 
	for (i = 0; i < vexnum; i++) {
		graph->vertices[i].firstarc = NULL;
		graph->vertices[i].data = i;
	}
	for (i = 0; i < vexnum; i++) {
		for (j = 0; j < vexnum; j++) {
			if (g[i][j]) {
				count++;
				tmp = (ArcNode *)malloc(sizeof(ArcNode));
				//无法分配内存 
				if (!tmp) {
					exit(OVERFLOW);
				}
				tmp->adjvex = j;
				tmp->nextarc = NULL;
				tmp->info = NULL;
				last = graph->vertices[i].firstarc; 
				if (last != NULL) {
					while (1) {
						//当last后没有下一条弧了 
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
					graph->vertices[i].firstarc = tmp;
				}
			} 
		}
	}
	graph->arcnum = count;
	graph->kind = kind;
	return OK;
}

void findInDegree(ALGraph *graph, int *indegree) {
	int i;
	ArcNode *tmp;
	//初始化数组 
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

int topologicalSort(ALGraph *graph) {
	int indegree[MAX_VERTEX_NUM];
	Stack *s;
	int i, j;
	ArcNode *tmp;
	//记录输出顶点数 
	int count;
	s = (Stack *)malloc(sizeof(Stack));
	//内存分配失败 
	if (!s) {
		exit(OVERFLOW);
	}
	findInDegree(graph, indegree);
	initStack(s);
	for (i = 0; i < graph->vexnum; i++) {
		if (!indegree[i]) {
			push(s, i);
		}
	} 
	count = 0;
	while (!stackEmpty(*s)) {
		pop(s, &i);
		printf("%d ", i);
		//输出并计数 
		count++;
		for (tmp = graph->vertices[i].firstarc; tmp; tmp = tmp->nextarc) {
			j = tmp->adjvex;
			indegree[j]--;
			if (!indegree[j]) {
				push(s, j);
			} 
		} 
	}
	//有环 
	if (count < graph->vexnum) {
		return ERROR;
	}
	else {
		return OK;
	} 
}

int main(int argc, char *argv[]) {
	int **g;
	int i, j;
	ALGraph *graph;
	g = (int **)malloc(12 * sizeof(int *));
	for (i = 0; i < 12; i++) {
		g[i] = (int *)malloc(12 * sizeof(int));
	}
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			g[i][j] = 0;
		}
	}
	g[0][3] = 1;
	g[0][1] = 1;
	g[0][2] = 1;
	g[0][11] = 1;
	g[3][4] = 1;
	g[4][6] = 1;
	g[2][4] = 1;
	g[2][6] = 1;
	g[2][7] = 1;
	g[1][2] = 1;
	g[8][9] = 1;
	g[8][11] = 1;
	g[8][10] = 1;
	g[9][11] = 1;
	g[10][5] = 1;
	g[5][7] = 1;
	graph = (ALGraph *)malloc(sizeof(ALGraph));
	createGraph(graph, g, 12, Digraph);
	topologicalSort(graph);
	return 0;
}
