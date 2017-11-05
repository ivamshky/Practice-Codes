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

void segregate012(vector<int> &A, int n){
    int lo = 0, hi = n-1, mid = 0;

    while(mid<=hi){
        switch(A[mid]){
		case 0:
			swap(A[mid++],A[lo++]);
			break;
		case 1:
			mid++;
			break;
		case 2:
            swap(A[mid],A[hi--]);
            break;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
		int n;
		cin>>n;
		vector<int> A(n);
		FORSC(A,0,n);
        segregate012(A,n);
		FOROUT(A,0,n);
		cout<<endl;
    }

	return 0;
}
