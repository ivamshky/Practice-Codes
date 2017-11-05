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
#define pi(n) printf("%d",&n)
#define pn printf("\n")
#define pl(n) cout<<n

int gcd(int a, int b){
    int tmp;
    while(b){
        a%=b;
        tmp=a;
        a=b;
        b=tmp;
    }
    return a;
}

int BinarySearch(vector<long int> A, long int k){
    int s = A.sz;
    int low = 0,high = s-1,mid;
    while(low<=high){
        mid=(high+low)/2;
        if(A[mid]==k)
            return mid;
        else if(A[mid]<k){
            low = mid+1;
        }
        else if(A[mid]>k){
            high = mid-1;
        }
    }
    return -1;
}

inline void solve(){
    int n;
    cin>>n;
    vector<long int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int k;
    cin>>k;
    --k;
    long int num_johny = A[k];
    sort(A.begin(),A.end());
    int nm = BinarySearch(A,num_johny);
    cout<<nm+1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








