#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> A;
vector<vector<int>> dp;
ll getMinTime(vector<int> A){
    ll DP[A.size()];
    DP[0] = A[0], DP[1] = A[1], DP[2] = A[2];
    int N = A.size();
    for(int i=3;i<N;++i)
        DP[i] = A[i]+min(DP[i-1],min(DP[i-2],DP[i-3]));

    return min(DP[N-1], min(DP[N-2],DP[N-3]));

}

ll rec(int day, int rest){
    if(day == A.size())
        return 0;
    if(rest == 3)
        return INT_MAX;

    if(dp[day][rest]!=-1)
        return dp[day][rest];
    else{
        dp[day][rest] = min(A[day]+rec(day+1,0), rec(day+1,rest+1));
        return dp[day][rest];
    }
}

int main(){
    int n;
    cin>>n;
    A.resize(n,0);
    for(int i=0;i<n;++i)
        cin>>A[i];
    dp.resize(n, vector<int>(3,-1));

//    cout<<getMinTime(A)<<endl;
    dp[n-1][0] = 0, dp[n-1][1] = 0, dp[n-1][2] = A[n-1];
    cout<<rec(0,0)<<endl;
    return 0;
}
