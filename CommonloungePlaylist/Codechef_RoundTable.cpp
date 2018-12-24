#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin>>n;

    vector<int> A(n);
    for(int i=0;i<n;++i)
        cin>>A[i];

    ll cost[n];
    ll minCost = INT_MAX;

    //First case: Knight 0 gets his sweet, Doesn't matter (n-1)th Knight gets or not
    cost[0] = A[0];
    cost[1] = A[1]+cost[0];
    cost[2] = A[2]+cost[0]; //knight 1 doesn't gets sweet.

    for(int i=3; i<n;++i)
        cost[i] = A[i] + min(cost[i-1],cost[i-2]);

    minCost = min(cost[n-1],cost[n-2]); //Knight N-1 might or might not get sweet.

    //Second case: Knight N-1 definitely gets his sweet, 0th may or may not get.
    cost[0] = A[0];
    cost[1] = A[1];
    for(int i=2;i<n;++i)
        cost[i] = A[i]+min(cost[i-1],cost[i-2]);
    minCost = min(minCost,cost[n-1]);
    cout<<minCost<<endl;
    return 0;
}
