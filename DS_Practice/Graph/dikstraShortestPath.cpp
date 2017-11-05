#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;

// UnDirected Graph

class Graph{
	int V;
	list<pair<int,int>> *adj;
	void printPath(vector<int> parent, int i);
public:
	Graph(int v): V(v), adj(new list<pair<int,int> >[V]){}

	void addEdge(int v, int u, int w){
		adj[u].push_back(make_pair(w,v));
        adj[v].push_back(make_pair(w,u));
	}
	void printSolution(vector<int>, int, vector<int>);
	void shortestPath(int src);
};

void Graph::printPath(vector<int> parent, int i)
{
	if(parent[i]==-1)
		return;
	printPath(parent,parent[i]);
	cout<<"->"<<i;
}

void Graph::printSolution(vector<int> dist, int n, vector<int> parent)
{
    int src = 0;
    cout<<"Vertex \t Distance \t Path"<<endl;
    for(int i=1;i<n;i++){
		cout<<src<<"->"<<i<<'\t'<<dist[i]<<'\t'<<src;
		printPath(parent,i);
		cout<<endl;
    }
}


void Graph::shortestPath(int src)
{
	set<pair<int,int> > setds;
	vector<int> dist(V,INF);
	setds.insert(make_pair(0,src));
    dist[src] = 0;
    vector<int> parent(V,-1);


    while(!setds.empty()){
		pair<int,int> tmp = *(setds.begin());
		setds.erase(setds.begin());
		int u = tmp.second;
		for(auto i = adj[u].begin();i!=adj[u].end();++i){
			int v = (*i).second;
			int wt = (*i).first;
			if(dist[v]>dist[u]+wt){
				if(dist[v]!=INF)
					setds.erase(setds.find(make_pair(dist[v],v)));
				dist[v] = dist[u]+wt;
				setds.insert(make_pair(dist[v],v));
				parent[v] = u;
			}
		}
    }

    printSolution(dist,V,parent);
}

int main()
{
	int V = 9;
    Graph g(V);
    Graph ng(3);
    ng.addEdge(0,1,5);
    ng.addEdge(0,2,2);
    ng.addEdge(1,2,-10);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    ng.shortestPath(0);
    return 0;
}
