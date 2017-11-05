#include<bits/stdc++.h>
using namespace std;
typedef unsigned long int ulint;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    ulint N,X,Y,a,b;
    cin>>N>>X>>Y;
    vector<pair<ulint,ulint> > exam(N);
    vector<ulint> V(X);
    vector<ulint> W(Y);

    for(ulint i=0;i<N;++i){
		cin>>a>>b;
		exam[i].first=a;
		exam[i].second=b;
    }
    for(ulint i=0;i<X;++i)
		cin>>V[i];
	for(ulint i=0;i<Y;++i)
		cin>>W[i];

	sort(V.begin(),V.end());
	sort(W.begin(),W.end());
	ulint min_tym = INT_MAX;
    for(ulint i=0;i<N;++i){

        ulint t1 = V[upper_bound(V.begin(),V.end(),exam[i].first)-V.begin()-1];
        ulint t2 = W[lower_bound(W.begin(),W.end(),exam[i].second)-W.begin()];
        //cout<<t2<<" "<<t1<<endl;
        min_tym = min(min_tym,t2-t1+1);
    }
    cout<<min_tym<<endl;
    return 0;
}
