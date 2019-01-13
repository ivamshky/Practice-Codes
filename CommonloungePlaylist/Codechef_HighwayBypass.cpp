#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mod = 20011;

bool grid[305][305];
ll dp[305][305][305][2];
ll r, c, d;

ll getWays(ll i, ll j, ll step, bool dir){
    if(i==r-1 && j == c-1)
        return 1;

    if(i>=r || j>=c || grid[i][j]==0)
        return 0;

    if(dp[i][j][step][dir] != -1)
        return dp[i][j][step][dir];

    ll t = 0;
    if(dir == 1){
        if(step < d){
            t = (t + getWays(i+1,j,step+1,1))%mod;
        }
        t = (t + getWays(i,j+1,1,0))%mod;
    }
    else{
        t = (t + getWays(i+1,j,1,1))%mod;
        if(step < d)
            t = (t + getWays(i,j+1,step+1,0))%mod;
    }
    dp[i][j][step][dir] = t;
    return t;
}

int main(){


    cin>>r>>c>>d;

    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j)
            cin>>grid[i][j];
    }


    memset(dp,-1, sizeof(dp));

    cout<<getWays(0,0,0,0);

    return 0;
}
