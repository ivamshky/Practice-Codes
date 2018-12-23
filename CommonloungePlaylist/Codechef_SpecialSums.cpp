#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll getSpecialSum(vector<ll> A, vector<ll> pref){

    int n = A.size();
    ll res = INT_MIN;
    ll curSum=0;
    vector<ll> diff(n,0), sum(n,0);
    diff[0] = A[0] - pref[0];
    sum[0] = A[0];
    for(int i=1;i<n;++i){
        diff[i] = max(diff[i-1], A[i]-pref[i]);
        sum[i] = max(sum[i-1], A[i]+pref[i-1]);
    }

    for(int i=1; i<n;++i){
            //For i<j
        res = max(res, diff[i-1]+A[i]+pref[i-1]);
    }

    for(int i=1;i<n;++i){
        //For i>j
        res = max(res, A[i]-pref[i]+pref[n-1]+sum[i-1]);
    }

    return res;
}


int main(){
    int n;
    cin>>n;
    vector<ll> A(n), pref(n);

    for(int i=0; i<n;++i){
        cin>>A[i];
    }

    ll x;

    for(int i=0; i<n; ++i){
        cin>>x;
        if(i ==0)
            pref[i] = x;
        else
            pref[i] = pref[i-1]+x;
    }

    cout<<getSpecialSum(A, pref);
    return 0;
}

