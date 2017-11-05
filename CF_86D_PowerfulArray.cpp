#include <bits/stdc++.h>
using namespace std;
#define N 200003
long long int F[1000007]; //int cost me 4 WA :/
int BLOCK_SIZE;
long long int ans=0, result[N], arr[N];

struct node{
	int l,r,x;
}Q[N];

bool mo_comp(node x,node y){
    int block_x = x.l/BLOCK_SIZE;
    int block_y = y.l/BLOCK_SIZE;
    if(block_x != block_y)
		return block_x < block_y;

	return x.r < y.r;
}

inline void add(int val)
{
    ans -= F[val]*F[val]*val;
    F[val]++;
    ans += F[val]*F[val]*val;
}

inline void rem(int val)
{
	ans -= F[val]*F[val]*val;
    F[val]--;
    ans += F[val]*F[val]*val;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,t;
	cin>>n>>t;
	BLOCK_SIZE = (int) sqrt(n);
    for(int i=0;i<n;i++)
		cin>>arr[i];

    for(int i=0;i<t;i++){
		cin>>Q[i].l>>Q[i].r;
		Q[i].x = i;
		Q[i].l -=1;
		Q[i].r -=1;
    }
    sort(Q,Q+t,mo_comp);

    int L=0,R=-1;
    for(int i=0;i<t;i++){
		int l=Q[i].l, r=Q[i].r;
		while(L<l){
			rem(arr[L]);
			L++;
		}
		while(L>l){
			L--;
			add(arr[L]);
		}
		while(R<r){
			R++;
			add(arr[R]);
		}
		while(R>r){
			rem(arr[R]);
			R--;
		}
		result[Q[i].x] = ans;
    }

    for(int i=0;i<t;i++){
		cout<<result[i]<<"\n";
    }
    return 0;
}
