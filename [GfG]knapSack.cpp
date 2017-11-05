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

int knapsack(vector<int> val, vector<int> wt, int W, int n)
{
    int DP[n+1][W+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                DP[i][j]=0;
            }
            else if(wt[i-1]>j){
                DP[i][j] = DP[i-1][j];
            }
            else if(wt[i-1]<=j){
                DP[i][j] = max(val[i-1]+DP[i-1][j-wt[i-1]], DP[i-1][j]);
            }
        }
    }
    return DP[n][W];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, W;
        cin>>n;
        cin>>W;
        vector<int> val(n);
        vector<int> wt(n);
        FORSC(val,0,n)
        FORSC(wt,0,n);

        cout<<knapsack(val,wt,W,n)<<endl;

    }
	return 0;
}
