#include<iostream>
#include<climits>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<list>

#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}

using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> Arrival(n);
		vector<int> Dep(n);
		FORSC(Arrival,0,n);
		FORSC(Dep,0,n);
        sort(Arrival.begin(),Arrival.end());
        sort(Dep.begin(),Dep.end());

        int plat = 1, res = 1;
        int a=1,d=0;
        while(a<n && d<n){
			if(Arrival[a] < Dep[d]){
				plat++;
				a++;
				res = max(res,plat);
			}
			else{
				plat--;
				d++;
			}
        }
        cout<<res<<endl;
	}

	return 0;
}
