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

int searchKey(vector<int>& A, int key, int l, int r)
{
    if(l>r) return -1;

    int mid = (l+r)/2;
    if(A[mid]==key) return mid;
    //Sorted
    if(A[l]<=A[mid]){
		if(key >= A[l] && key <= A[mid]){
			return searchKey(A,key,l,mid-1);
		}
		return searchKey(A,key,mid+1,r);
    }

    if(key>=A[mid] && key <=A[r]){
		return searchKey(A,key,mid+1,r);
    }

    return searchKey(A,key,l,mid-1);
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
        int key;
        cin>>key;

        cout<<searchKey(A,key,0,n-1)<<endl;

    }
	return 0;
}
