#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dp[5001];

int main()
{
    ll n;
    cin>>n;

    ll a[n];
    for(int i=0; i<n; ++i)
        cin>>a[i];

    memset(dp,1,sizeof(dp));

    for(int i=1; i<n;++i){
        for(int j = 0; j<i; ++j){
            if(abs(a[i]) > abs(a[j]) && a[j]^a[i] > 0)
                dp[i] = max(dp[i], 1+dp[j]);
        }
    }

    for(int i=0;i<n;++i)
        cout<<dp[i]<<" ";

    cout<<endl;
    return 0;
}
