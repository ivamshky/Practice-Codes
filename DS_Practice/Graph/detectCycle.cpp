#include <iostream>
#include <list>
#include <limits>
using namespace std;

// Finding Cycle in a Directed Graph
class Graph{
    int V;
    list<int> *adj;
    bool isCycleUtil(int v, bool visited[], bool *rs);
public:
	Graph(int v):V(v){
		adj = new list<int>[V];
	};

	bool isCyclic();
	void addEdge(int v, int w);
};

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

bool Graph::isCycleUtil(int v, bool visited[], bool *recS){
	if(visited[v]==false){
		visited[v] = true;
		recS[v] = true;

		list<int>::iterator it;
		for(it=adj[v].begin();it!=adj[v].end();++it){
			if(!visited[*it] && isCycleUtil(*it, visited, recS)){
				return true;
			}
			else if(recS[*it]==true)
				return true;
		}
	}
	recS[v] = false;
	return false;
}

bool Graph::isCyclic(){
	bool *visited = new bool[V];
	bool *recS = new bool[V];

	for(int i=0; i<V;i++){
		visited[i] = false;
		recS[i] = false;
	}
	for(int i=0;i<V;i++){
		if(isCycleUtil(i, visited, recS))
			return true;
	}
	return false;
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if(g.isCyclic())
		cout<<"Graph has a Cycle"<<endl;
	else
		cout<<"No Cycle Present"<<1<<endl;
	return 0;
}
