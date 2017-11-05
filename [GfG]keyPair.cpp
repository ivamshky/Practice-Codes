#include<iostream>
#include<climits>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
using namespace std;
#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n, sum;
		cin>>n>>sum;
		vector<int> A(n);
		FORSC(A,0,n);
        sort(A.begin(),A.end());
        int i=0;
        bool yes=0;
        while(A[i]<sum && i<n){
			int key = sum-A[i];

			if(binary_search(A.begin(),A.end(),key)){
				yes=1;
				break;
			}
			else{
				i++;
				continue;
			}
        }
        if(yes)
			cout<<"YES"<<endl;
		else
        cout<<"NO"<<endl;
	}
	return 0;
}
