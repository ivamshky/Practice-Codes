#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n, k;
    cin>>n>>k;
    k--;
    vector<int> A(n);

    for(int i=0;i<n;++i)
        cin>>A[i];

    vector<ll> rightCost(n,0);
    vector<ll> leftCost(n,0);
    for(int i=k;i<n;++i){
        if(i==k) rightCost[i] = 0;
        else if(i==k+1) rightCost[i] = A[i];
        else rightCost[i] = A[i] + max(rightCost[i-1], rightCost[i-2]);
    }

    leftCost[1] = A[0];
    for(int i=2;i<n;++i){
        leftCost[i] = max(leftCost[i-1]+A[i-1], leftCost[i-2]+A[i-2]);
    }
    ll res = LONG_MIN;
    for(int i=k;i<n;++i)
        res = max(res,leftCost[i]+rightCost[i]);

    cout<<res<<endl;
    return 0;


}
