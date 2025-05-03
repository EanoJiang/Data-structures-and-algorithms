#include <stdio.h>

//顶点
typedef char VertexType;
//边
typedef int EdgeType;

#define MAXSIZE 100

//邻接矩阵
typedef struct Matrix_Graph
{
    //顶点数组
	VertexType vertex[MAXSIZE];
    //边数组
	EdgeType arc[MAXSIZE][MAXSIZE];
    //顶点数
	int vertex_num;
    //边数
	int edge_num;
}Matrix_Graph;


//创建图
void create_graph(Matrix_Graph* G)
{
	G->vertex_num = 9;
	G->edge_num = 15;
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[i][j] = 0;
		}
	}
    /*连线*/
	//A-B A-F
	G->arc[0][1] = 1;
	G->arc[0][5] = 1;

	//B-C B-G B-I
	G->arc[1][2] = 1;
	G->arc[1][6] = 1;
	G->arc[1][8] = 1;

	//C-D C-I
	G->arc[2][3] = 1;
	G->arc[2][8] = 1;

	//D-E D-G D-H D-I
	G->arc[3][4] = 1;
	G->arc[3][6] = 1;
	G->arc[3][7] = 1;
	G->arc[3][8] = 1;

	//E-F E-H
	G->arc[4][5] = 1;
	G->arc[4][7] = 1;

	//F-G
	G->arc[5][6] = 1;

	//G-H
	G->arc[6][7] = 1;

    //无向图，所以直接把出边的值斜对角对称赋值给入边
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

//标志位数组：用来标记某个顶点是否已经遍历过
int visited[MAXSIZE];

void dfs(Matrix_Graph G, int i)
{
	visited[i] = 1;
	printf("%c\n", G.vertex[i]);

	for (int j = 0; j < G.vertex_num; j++)
	{
		if (G.arc[i][j] == 1 && visited[j] == 0)
		{
            //递归，把未遍历过的下一个顶点作为参数传入
			dfs(G, j);
		}
	}
}

int main(int argc, char const *argv[])
{
	Matrix_Graph G;
	create_graph(&G);

    //初始化标志位数组
	for (int i = 0; i < G.vertex_num; i++)
	{
		visited[i] = 0;
	}

	dfs(G, 0);
	return 0;
}