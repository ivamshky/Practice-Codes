#include<iostream>
#include<climits>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<list>

#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}

using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        FORSC(A,0,n);
        int dp[n+1];

        dp[0] = A[0];
        dp[1] = max(A[1],A[0]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-2]+A[i],dp[i-1]);
        }
        cout<<dp[n-1]<<endl;
    }
	return 0;
}
