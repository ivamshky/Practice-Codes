#include <bits/stdc++.h>
using namespace std;

void sieve(int n,vector<int> &prime)
{
    bool mark[n+1];
    memset(mark,true,sizeof(mark));
    for(int i=2;i*i<n;i++){
        if(mark[i]){
            for(int j=i*2;j*j<n;j+=i)
                mark[j]=false;
        }
    }
    for(int i=2;i<n;i++)
        if(mark[i])
            prime.push_back(i);
}

void segmented_sieve(int l,int r)
{

    bool mark[r-l+1];
    memset(mark,true,sizeof(mark));
    for(int i=2;i*i<=r;i++){
        for(int j=max(i*i,(l+(i-1))/i*i);j<=r;j+=i)
            mark[j-l]=false;
    }
    for(int i=max(l,2);i<=r;i++)
        if(mark[i-l])
            cout<<i<<" ";
}

int main()
{
    int a,b;
    cin>>a>>b;
    segmented_sieve(a,b);
    return 0;
}
