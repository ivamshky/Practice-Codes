#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void topologicalSortUtil(int v, vector<bool>&, stack<int>& st);
public:
	void addEdge(int u, int v);
	Graph(int v): V(v), adj(new list<int>[V]){}
	void topologicalSort();

};
//Directed Graph
void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	//adj[v].push_back(u);
}

void Graph::topologicalSortUtil(int v, vector<bool>& vis, stack<int>& st)
{
    vis[v] = true;
    for(auto it=adj[v].begin();it!=adj[v].end();++it){
		if(!vis[*it]){
			topologicalSortUtil(*it,vis,st);
		}
    }
    st.push(v);
}

void Graph::topologicalSort(){
	vector<bool> vis(V,false);
	stack<int> st;
	for(int i=0;i<V;i++){
		if(!vis[i])
			topologicalSortUtil(i,vis,st);
	}

	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

int main(){
	Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}
