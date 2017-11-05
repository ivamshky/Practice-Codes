#include<iostream>
#include<climits>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<list>

#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,sum;
		cin>>n>>sum;
		vector<int> A(n);
		FORSC(A,0,n);
        int l=0, r=0;
        int cur_sum=A[l];
        while(l<n && r<n){
			//cout<<"1"<<cur_sum<<" "<<endl;
			if(cur_sum<sum){
				cur_sum += A[++r];
			}

			if(cur_sum > sum){
				cur_sum -= A[l++];
			}

			if(cur_sum == sum){
				if(l>r) swap(l,r);
				cout<<l+1<<" "<<r+1<<endl;
				break;
			}


			if(r>=n && l>=n){
				cout<<"-1"<<endl;
				break;
			}
        }
	}
	return 0;
}
