#include <cstdio>
using namespace std;
#define V 4
#define INF 99999

void printSolution(int dist[][V])
{
    printf("Shortest Distance Matrix\n");

	for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(dist[i][j]==INF)
					printf("%7s","INF");
				else
					printf("%7d",dist[i][j]);
			}
		printf("\n");
	}

}


void floydWarshall(int graph[][V])
{
    int dist[V][V];

    for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			dist[i][j] = graph[i][j];

	printf("Graph Matrix\n");

	for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(dist[i][j]==INF)
					printf("%7s","INF");
				else
					printf("%7d",dist[i][j]);
			}
		printf("\n");
	}

    for(int k=0;k<V;k++){ //Checking every vertex as Intermediate Vertex.
		for(int i=0;i<V;i++){ //Source
			for(int j=0;j<V;j++){ //Destination
				if(dist[i][k]+dist[k][j] < dist[i][j]){	//if path through intermediate
						//vertex is shortest or not
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
    }

//    printSolution(dist);
	printf("Shortest Distance Matrix\n");

	for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(dist[i][j]==INF)
					printf("%7s","INF");
				else
					printf("%7d",dist[i][j]);
			}
		printf("\n");
	}
}

int main()
{
	int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    // Print the solution
    floydWarshall(graph);
    return 0;
}
