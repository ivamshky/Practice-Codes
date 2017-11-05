#include<bits/stdc++.h>
using namespace std;

void getPrimes_Sieve(int n)
{
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;

    for(int p=2;p*p<=n;p++){
        if(prime[p]){
            for(int i=p*2;i<=n;i+=p){
                prime[i] = false;
            }
        }
    }

    for(int i=0;i<=n;i++){
        if(prime[i])
            cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    getPrimes_Sieve(n);
    return 0;
}
