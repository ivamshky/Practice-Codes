#include <bits/stdc++.h>
using namespace std;

struct edge{
	int src, dest, wt;
};

struct Graph
{
	int v,e;
	struct edge *edges;
};

Graph *createGraph(int v, int e)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));

    graph->v = v;
    graph->e = e;

    graph->edges = (edge *)malloc(graph->e*sizeof(edge));
    return graph;
}

void printSol(int dist[], int n){
	printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void BellmanFord(Graph *graph, int src){

	int v = graph->v;
	int e = graph->e;
	int dist[v];
	for (int i = 0; i < v; i++)
        dist[i]   = INT_MAX;
	dist[src] = 0;

    for(int i=0;i<v-1;i++){
		for(int j=0;j<e;j++){
			int u = graph->edges[j].src;
			int v = graph->edges[j].dest;
			int wt = graph->edges[j].wt;

			if(dist[u]!=INT_MAX && dist[u]+wt < dist[v]){
				dist[v] = dist[u]+wt;
			}
		}
    }

    for(int i=0;i<e;i++){
		int u = graph->edges[i].src;
		int v = graph->edges[i].dest;
		int wt = graph->edges[i].wt;

		if(dist[u]!=INT_MAX && dist[u]+wt < dist[v]){
			cout<<"Graph Has -ve weight Cycle\n";
		}
    }

    printSol(dist,v);
}

int main(){
	int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    Graph* graph = createGraph(V, E);

    // add edge 0-1 (or A-B in above figure)
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].wt = -1;

    // add edges 0-2 (or A-C in above figure)
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].wt = 4;

    // add edges 1-2 (or B-C in above figure)
    graph->edges[2].src = 1;
    graph->edges[2].dest = 2;
    graph->edges[2].wt = 3;

    // add edges 1-3 (or B-D in above figure)
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].wt = 2;

    // add edges 1-4 (or A-E in above figure)
    graph->edges[4].src = 1;
    graph->edges[4].dest = 4;
    graph->edges[4].wt = 2;

    // add edges 3-2 (or D-C in above figure)
    graph->edges[5].src = 3;
    graph->edges[5].dest = 2;
    graph->edges[5].wt = 5;

    // add edges 3-1 (or D-B in above figure)
    graph->edges[6].src = 3;
    graph->edges[6].dest = 1;
    graph->edges[6].wt = 1;

    // add edges 4-3 (or E-D in above figure)
    graph->edges[7].src = 4;
    graph->edges[7].dest = 3;
    graph->edges[7].wt = -3;

    BellmanFord(graph, 0);

    return 0;
}
