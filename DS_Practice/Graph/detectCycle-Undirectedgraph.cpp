#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	bool isCycleUtil(int v, vector<bool>& vis, int parent);
public:
	void addEdge(int u, int v);
	Graph(int v): V(v), adj(new list<int>[V]){}
	bool isCyclic();
};

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Graph::isCycleUtil(int v, vector<bool>& vis, int parent)
{
	vis[v] = true;
	for(auto i = adj[v].begin();i!=adj[v].end();++i){
		if(!vis[*i]){
			if(isCycleUtil(*i, vis, v))
				return true;
		}
		else if(*i!=parent){
			return true;
		}
	}
	return false;
}

bool Graph::isCyclic()
{
    vector<bool> vis(V, false);

    for(int u = 0;u<V;u++){
		if(!vis[u])
			if(isCycleUtil(u,vis,-1))
				return true;
    }
    return false;
}

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

    return 0;
}
