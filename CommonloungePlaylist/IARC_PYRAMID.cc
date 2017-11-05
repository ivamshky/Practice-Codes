#include<bits/stdc++.h>
using namespace std;
typedef unsigned long int ulint;
typedef vector<pair<ulint,ulint> > vec;
int compare(pair<ulint,ulint> a, pair<ulint,ulint> b)
{
    return a.first - b.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ulint n,x,y;
    cin>>n;
    vec ar(n);
    for(ulint i=0;i<n;i++){
		cin>>x>>y;
		ar[i].first=min(x,y);
		ar[i].second=max(x,y);
    }
    sort(ar.begin(),ar.end());

    ulint lev=0;
    for(ulint i=0;i<n;++i){
        if(ar[i].first >= lev+1)
			lev++;
    }
    cout<<lev<<endl;
    return 0;
}
