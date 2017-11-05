#include <bits/stdc++.h>
using namespace std;

#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}
double DP[1001][1001] = {0.0};
double findWater(double K, int r, int c)
{
    if(c > r)
		return -1.0;
	DP[1][1] = K;
	for(int i=1;i<=r;++i){
		for(int j=1;j<=i;++j){
            if(DP[i][j]>1.0){
				double K = DP[i][j]-1.0;
				DP[i][j] = 1.0;
				DP[i+1][j]+=K/2.0;
				DP[i+1][j+1]+=K/2.0;
            }
		}
	}
	return DP[r][c];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
		int r,c;
		double K;
		cin>>K;
		cin>>r;
		cin>>c;
		cout<<fixed;
		cout<<setprecision(6)<<findWater(K,r,c)<<endl;
    }
}
