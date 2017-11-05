#include <bits/stdc++.h>
using namespace std;

#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}

int main()
{
    int t;
    cin>>t;
    while(t--){
		int k,n;
		cin>>k;
		cin>>n;
        int H[n];
        FORSC(H,0,n);
        sort(H,H+n);
        int ans = H[n-1]-H[0];
        int small = H[0]+k;
        int large = H[n-1]-k;
        if(small>large)
			swap(small,large);
		for(int i=1;i<n-1;++i){
			int add = H[i]+k;
			int sub = H[i]-k;

			if(add <= large || sub>=small)
				continue;
			if(large-sub <= add - small)
				small = sub;
			else
				large = add;

		}
		cout<<min(ans,large-small)<<endl;
    }
}
