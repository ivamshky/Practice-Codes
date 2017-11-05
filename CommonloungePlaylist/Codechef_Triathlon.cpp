#include<bits/stdc++.h>
using namespace std;
//#define FIN 0

struct times{
	int a,b,c;
	int sum;
};

bool cmp(times a,times b){
	return a.sum>b.sum;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	#ifdef FIN
	freopen("triathlon_in.in","r",stdin);
	#endif
    int n;
    cin>>n;
    vector<times> A(n);
    for(int i=0;i<n;i++){
		cin>>A[i].a>>A[i].b>>A[i].c;
        A[i].sum = A[i].b+A[i].c;
    }

    sort(A.begin(),A.end(),cmp);
    int ans = A[0].sum+A[0].a;
    int prev = A[0].a;
    for(int i=1;i<n;i++){
		ans = max(ans,prev+A[i].sum+A[i].a);
		prev += A[i].a;
    }
    cout<<ans<<endl;
    return 0;
}
