#include <bits/stdc++.h>
using namespace std;


#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}

bool comp(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int S[n],E[n];
		FORSC(S,0,n);
		FORSC(E,0,n);
		vector<pair<int,int> > V;
		for(int i=0;i<n;++i){
			V.push_back(make_pair(S[i],E[i]));
		}
		sort(V.begin(),V.end(),comp);

		int res=1,j=0;
		for(int i=1;i<n;++i){
            if(V[i].first>=V[j].second){
				res++;
				j=i;
            }
		}
		cout<<res<<endl;
	}
}
