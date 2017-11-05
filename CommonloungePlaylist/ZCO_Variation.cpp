#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll N,K;
	cin>>N>>K;
    vector<ll> v(N);
    for(int i=0;i<N;i++){
		cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll pairs = 0;
    for(int i=0;i<N;++i){
		if(lower_bound(v.begin(),v.end(),v[i]+K) != v.end()){
			pairs += N-(lower_bound(v.begin(),v.end(),v[i]+K)-v.begin());
			//break;
		}
    }
    cout<<pairs<<endl;
}
