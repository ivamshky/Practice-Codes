#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

// Iterative Traversal for Directed Graph
class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(int v): V(v), adj(new list<int>[V]){}

	void addEdge(int v, int u);
	void DFS(int s);
};

void Graph::addEdge(int v, int u)
{
	adj[v].push_back(u);
}

void Graph::DFS(int s)
{
    vector<bool> vis(V,s);
    stack<int> st;
    st.push(s);
    while(!st.empty()){
		s = st.top();
		st.pop();
		if(!vis[s]){
			cout<<s<<" ";
			vis[s] = true;
		}

		for(auto i = adj[s].begin();i!=adj[s].end();i++){
			if(!vis[*i])
				st.push(*i);
		}
    }
}

int main()
{
	Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);

    cout << "Following is Depth First Traversal\n";
    g.DFS(0);
}
