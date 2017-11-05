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
        int i=0;
        while(i<n-1 && A[i]<A[i+1]){
            i++;
        }
        if(i==n-1){
            cout<<A[0]<<endl;
        }
        else
            cout<<A[i+1]<<endl;
    }
	return 0;
}
