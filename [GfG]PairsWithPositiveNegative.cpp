#include<iostream>
#include<climits>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<unordered_map>

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
        int M[2001] = {0};
        for(int i=0;i<n;++i){
            int a;
            cin>>a;
            M[1000+a]++;
        }
        bool f=false;
        int a,b;
        for(int i=1;i<=1000;++i){
            a = 1000-i;
            b = 1000+i;
            int c = min(M[a],M[b]);
            for(int k=0;k<c;++k){
                f=true;
                cout<<a-1000<<" "<<b-1000<<" ";
            }
        }
        if(!f)
            cout<<0<<endl;
        else
            cout<<endl;


    }

	return 0;
}
