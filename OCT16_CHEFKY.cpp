#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>

//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <fstream>
#include <limits>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end()
#define gi(n) scanf("%d",&n);
#define gl(n) cin>>n
#define pi(n) printf("%d",n)
#define pn printf("\n")
#define pl(n) cout<<n

int main(){
    int t;
    gi(t);
    while(t--){
        long int n,m,c,a=0;
        cin>>n>>m>>c;
        if(c > m*n){
            pi(a);
            pn;
            continue;
        }
        for(long int i=1;i<=c;++i){
            if(i<=n && (long int)c/i<=m && i*(c/i)==c)
                a++;
        }
        pl(a);
        pn;
    }
    return 0;
}







