#include <stdio.h>
#include<stdlib.h>

#define MAX 10


typedef struct Node
{
	int vertex;
	struct Node* next;
}Node;


Node* adjList[MAX];
int visited[MAX] = { 0 };


typedef struct
{
	int data[MAX];
	int top;
}Stack;


void initStack(Stack* s)
{
	s->top = -1;
}


int isEmpty(Stack* s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

void push(Stack* s,int v)
{
	s->data[++(s->top)] = v;
}

int pop(Stack* s)
{
	return s->data[(s->top)--];
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


void dfs_stack(int start)
{
	Stack s;
	initStack(&s);

	push(&s, start);

	while (!isEmpty(&s))
	{
		int v = pop(&s);

		if (!visited[v])
		{
			visited[v] = 1;
			printf("%d ", v);

			Node* temp = adjList[v];
			while (temp != NULL)
			{
				if (!visited[temp->vertex])
					push(&s, temp->vertex);
				temp = temp->next;
			}
		}
	}
}


int main()
{
	for (int i = 0; i < MAX; i++)
		adjList[i] = NULL;

	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(1, 3);
	addEdge(2, 4);


	printf("DFS 방문 순서: ");
	dfs_stack(0);
	printf("\n");

	return 0;
}