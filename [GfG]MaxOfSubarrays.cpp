#include<iostream>
#include<climits>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}

using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> A(n);
		FORSC(A,0,n);

        int i=0;
		deque<int> Q(k)
		for(;i<k;i++){
			while(!Q.empty() && A[i]>=A[Q.back()])
				Q.pop_back();
            Q.push_back(i);
		}

		for(;i<n;++i){
			cout<<A[Q.front()]<<" ";
			while(!Q.empty() && Q.front()<=i-k)
				Q.pop_front();

			while(!Q.empty() && A[i]>=A[Q.back()])
				Q.pop_back();

			Q.push_back(i);
		}

		cout<<A[Q.front()]<<endl;


	}

	return 0;
}
