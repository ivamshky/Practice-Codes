#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool comp(LL a,LL b){
	return a>b;
}
int main()
{
    ios_base::sync_with_stdio(0);
  //  cin.tie(NULL);

	LL N,M;
	cin>>N>>M;
	queue<LL> q1;
	queue<LL> q2;
	LL a[N];
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	sort(a,a+N,comp);
	for(int i=0;i<N;i++){
		q1.push(a[i]);
	}
    LL ans[63000005];
    for(int i=1;i<=63000000;++i){
		if(q2.empty()){
			if(q1.empty())
				break;
			LL x = q1.front();
			q1.pop();
			ans[i]=x;
			q2.push(x/2);
		}
		else if(q1.empty()){
			LL x = q2.front();
			q2.pop();
			ans[i]=x;
			q2.push(x/2);
		}
		else{
			LL x = q1.front();
			LL y = q2.front();
			if(x>y){
				ans[i] = x;
				q2.push(x/2);
				q1.pop();
			}
			else{
				ans[i] = y;
				q2.push(y/2);
				q2.pop();
			}
		}
    }
    while(M--){
		int q;
		cin>>q;
		cout<<ans[q]<<endl;
    }
	return 0;
}
