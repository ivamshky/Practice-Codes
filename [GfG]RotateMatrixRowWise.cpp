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
        int m,n,k;
        cin>>m>>n>>k;
        int A[m][n];
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j)
                cin>>A[i][j];
        }
        k = k%n;
        int a=0;
        for(int j=0;j<m;j++)
            for(int i=k,x=0;x<n;++x,i=(++i%n)){
                cout<<A[j][i]<<" ";
                a++;
            }
        cout<<endl;
        // cout<<a<<endl;
    }

	return 0;
}