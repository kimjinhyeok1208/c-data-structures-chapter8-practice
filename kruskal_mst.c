#include <stdio.h>
#include <stdlib.h>

#define MAX 100


typedef struct
{
	int u, v, w;
}Edge;


Edge edges[MAX];
int parent[MAX];

void initSet(int n)
{
	for (int i = 0; i < n; i++)
		parent[i] = i;
}

int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

int unite(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
		return 0;

	parent[b] = a;
	return 1;
}

int compare(const void* a, const void* b)
{
	return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main()
{
	int n = 5, m = 7;
	int mstCost = 0, edgeUsed = 0;

	edges[0] = (Edge){ 0,1,4 };
	edges[1] = (Edge){ 0,2,3 };
	edges[2] = (Edge){ 1,2,1 };
	edges[3] = (Edge){ 1,3,2 };
	edges[4] = (Edge){ 2,3,4 };
	edges[5] = (Edge){ 3,4,2 };
	edges[6] = (Edge){ 2,4,5 };

	qsort(edges, m, sizeof(Edge), compare);
	initSet(n);

	for (int i = 0; i < m && edgeUsed < n - 1; i++)
	{
		if (unite(edges[i].u, edges[i].v))
		{
			mstCost += edges[i].w;
			edgeUsed++;
		}
	}

	printf("Minimum Spanning Tree Cost: %d\n", mstCost);
	return 0;
}