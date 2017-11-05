#include<bits/stdc++.h>
typedef long long ll;
#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}

using namespace std;
const int mod = 10e9+7;
ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	char x,y;
	cin>>x>>y;
	vector<int> X;
    vector<int> Y;
    for(int i=0;i<s.length();++i){
        if(s[i]==x)
            X.push_back(i);
        if(s[i]==y)
            Y.push_back(i);
    }
	int q;
	cin>>q;
	while(q--){
	    int l, r;
	    cin>>l>>r;
	    long long int c = 0;
	    for(int i=0;i<X.size();++i){
	        for(int j=0;j<Y.size();++j){
	            if(X[i]>=l && X[i]<=r && Y[j]>=l && Y[j]<=r && Y[j]>X[i])
	                c = (c+power(2,Y[j]-X[i]-1,mod))%mod;
	        }
	    }
	    cout<<c<<endl;
	}

	return 0;
}
