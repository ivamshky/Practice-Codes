#include <bits/stdc++.h>
using namespace std;


#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}

int minSwaps(int A[], int n)
{
    pair<int,int> arrPos[n];
    for(int i=0;i<n;++i){
		arrPos[i].first  = A[i];
		arrPos[i].second = i;
    }

    sort(arrPos,arrPos+n);
    vector<bool> vis(n,false);
    int ans = 0;

    for(int i = 0; i<n;++i){
		if(vis[i]||arrPos[i].second==i)
			continue;
		int cycle_size=0,j=i;
		while(!vis[j]){
			vis[j]=1;
			j = arrPos[j].second;
			cycle_size++;
		}
		ans += cycle_size-1;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
		int n;
		cin>>n;
        int A[n];
        FORSC(A,0,n);
        cout<<minSwaps(A,n)<<endl;
    }
}
