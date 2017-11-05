/* USING MO's Algorithm */

#include <bits/stdc++.h>
using namespace std;
vector <pair<pair<int,int>,int> > queries;
int F[1000001];
int BLOCK_SIZE;
int ans=0;
int arr[30003];
int result[200003];
bool mo_comp(const pair<pair<int,int>,int> &x,const pair<pair<int,int>,int> &y)
{
    int block_x = x.first.first/BLOCK_SIZE;
    int block_y = y.first.first/BLOCK_SIZE;
    if(block_x!=block_y)
		return block_x<block_y;
	return x.first.second < y.first.second;
}

void add(int pos)
{
	F[arr[pos]]++;
	if(F[arr[pos]]==1)
		ans++;
}

void rem(int pos)
{
	F[arr[pos]]--;
	if(F[arr[pos]]==0)
		ans--;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    cin>>N;
	BLOCK_SIZE = (int) sqrt(N);
    for(int i=0;i<N;i++)
		cin>>arr[i];
    cin>>Q;
	for(int i=0;i<Q;i++){
		int a,b,c=i;
		cin>>a>>b;
		queries.push_back(make_pair(make_pair(--a,--b),c));
	}
	sort(queries.begin(),queries.end(),mo_comp);
    int mo_left=0, mo_right=0;

    for(int i=0;i<Q;i++){
        int L = queries[i].first.first, R = queries[i].first.second;

        while(mo_left<L){
            rem(mo_left);
            mo_left++;
        }

        while(mo_left>L){
			add(mo_left-1);
			mo_left--;
        }

        while(mo_right>R+1){
			rem(mo_right-1);
			mo_right--;
        }

        while(mo_right<=R){
			add(mo_right);
			mo_right++;
        }
		result[queries[i].second] = ans;

    }

    for(int i=0;i<Q;i++){
		cout<<result[i]<<"\n";
    }
    return 0;
}
