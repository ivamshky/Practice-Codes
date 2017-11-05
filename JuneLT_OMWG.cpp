#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    int score=0;
    score = 2*m*n-n-m;
    cout<<score<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
