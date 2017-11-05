#include<bits/stdc++.h>
using namespace std;

// Finds out a^n-1 mod n;
int power(int a,int n,int p)
{
    int res=1;
    a = a%p; //In case a>p
    while(n>0){
        if(n%2==1)
            res = (res * a)%p;
        a = (a*a)%p;
        n = n>>1;
    }
    return res;
}

bool isPrime_fermat(int n,int k)
{
    if(n<=1 || n==4) return false;
    if(n<=3) return true;

    while(k>0){
        int a = 2+rand()%(n-4);
        // Fermat's Little theorem
        if(power(a,n-1,n)!=1)
            return false;
        k--;
    }
    return true;
}

int main()
{
    int n;
    int k=11;
    cin>>n;
    cout<<isPrime_fermat(n,k)<<endl;
    return 0;
}
