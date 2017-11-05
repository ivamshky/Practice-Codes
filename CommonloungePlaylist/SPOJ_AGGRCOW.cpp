#include <bits/stdc++.h>
using namespace std;
int N,C;
int func(int x,vector<int> A)
{
    int cowsplaced = 1;
    int len = A.size();
	int prev = A[0];
	for(int i=1;i<len;++i){
		if(A[i]-prev >= x){
			cowsplaced++;
			if(cowsplaced==C)
				return 1;
			prev = A[i];
		}
	}
	return 0;
}

int bin_search(vector<int> A)
{
    int start = 0;
    int len = A.size();
    int End = A[len-1];
    while(start<End){
		int mid = (start+End)/2;
        if(func(mid,A)==1)
			start = mid+1;
		else
			End = mid;
    }
    return start-1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){

		cin>>N>>C;
        vector<int> stalls(N);
        for(int i=0;i<N;i++)
			cin>>stalls[i];
		sort(stalls.begin(),stalls.end());

		cout<<bin_search(stalls)<<endl;
    }
}
