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
		vector<int> A(n);
		FORSC(A,0,n);

		int buy,cur_sell,sell,flag=0;
		buy=sell=0;
        while(sell<n){
			while(sell<n-1 && A[sell+1]>A[sell])
				sell++;
			if(buy==sell)
				buy++,sell++;
			else{
				sell = sell == n ? n-1 : sell;
				cout<<"("<<buy<<" "<<sell<<") ";
				buy = sell+1;
				sell = buy;
				flag=1;
			}
        }
        if(!flag)
			cout<<"No Profit";
        cout<<endl;
    }
	return 0;
}
