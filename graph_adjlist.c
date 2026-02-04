#include <stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct Node
{
	int vertex;
	struct Node* next;
}Node;


Node* adjList[MAX];
int n;


void initGraph(int vertices)
{
	n = vertices;
	for (int i = 0; i < n; i++)
		adjList[i] = NULL;
}


void addEdge(int u, int v)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->vertex = v;
	node->next = adjList[u];
	adjList[u] = node;

	node = (Node*)malloc(sizeof(Node));
	node->vertex = u;
	node->next = adjList[v];
	adjList[v] = node;
}


void printGraph()
{
	for (int i = 0; i < n; i++)
	{
		printf("%d: ", i);
		Node* temp = adjList[i];
		while (temp != NULL)
		{
			printf("%d ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main()
{
	initGraph(4);

	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(1, 3);

	printGraph();

	return 0;
}