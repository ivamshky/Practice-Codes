#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if(n<=1) return false;
    for(int a=2;a<n;a++)
        if(n%a==0)
            return false;
    return true;
}

bool isPrime_optimized(int n)
{
    if(n<=1) return false;
    if(n<=3) return true;
    if(!n%2 || !n%3)
        return false;
    int a=5;
    for(;a*a<=n;a+=6){
        if(!n%a || !n%(a+2))
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;

    cout<<isPrime(n)<<" ";

    cout<<isPrime_optimized(n)<<" ";

}
