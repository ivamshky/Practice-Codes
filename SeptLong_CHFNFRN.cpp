#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define MAX 1001
int G[MAX][MAX];
bool valid;
int color[MAX];
int n;
/**
        CLIQUE PROBLEM
            ALSO
        IF A GRAPH CAN BE PARTITIONED INTO TWO SETS
        THEN ITS COMPLEMENT SHOULD BE A BIPARTRITE GRAPH.
*/

void dfs(int cur,int side){
    if(color[cur]!=-1){
        if(color[cur]==side) return;
        valid=false;
        return;
    }
    color[cur]=side;
    for(int i=0;i<n;i++)
        if(G[cur][i])
            dfs(i,1-side);
}

void solve(){
    int x,y;
    long long int m;
    scanf("%d%lld",&n,&m);
    memset(G,1,sizeof(G));
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        x--;y--;
        G[x][y]=G[y][x]=0;
    }
    for(int i=0;i<n;i++)
        G[i][i]=0;
    valid=true;
    memset(color,-1,sizeof(color));
    for(int i=0;i<n;i++)
        if(color[i]==-1)
            dfs(i,0);
    printf("%s\n",valid?"YES":"NO");
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
