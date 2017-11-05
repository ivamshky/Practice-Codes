#include <bits/stdc++.h>

using namespace std;

long long int getZeroes(long long int N){
    long long int r=0;
    while(N>0){
        r += floor(N/5);
        N /= 5;
    }
    return r;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long int N;
        cin>>N;
        cout<<getZeroes(N)<<endl;
    }
    return 0;
}
