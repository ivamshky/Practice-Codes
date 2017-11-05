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
		int n,a;
		cin>>n;
        bool A[n];
        for(int i=0;i<n-1;i++){
			cin>>a;
			A[a-1]=true;
        }

        for(int i=0;i<n;i++){
			if(!A[i]){
				cout<<i+1<<endl;
				break;
			}
        }
	}


	return 0;
}
