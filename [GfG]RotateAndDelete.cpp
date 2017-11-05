#include<bits/stdc++.h>
using namespace std;


#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}

int main()
{
    int t;
    cin>>t;
    while(t--){
		int n;
		cin>>n;
        vector<int> A(n);
        FORSC(A,0,n);
        int N = n;
        for(int i=1;i<(n/2 +1);++i){
			A.insert(A.begin(),*(A.rbegin()));
			A.pop_back();
			A.erase(A.end()-i);
        }

        cout<<*(A.begin())<<endl;
    }
}
