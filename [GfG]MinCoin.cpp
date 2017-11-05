#include <bits/stdc++.h>
using namespace std;

#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}

int main()
{
    int t;
    cin>>t;
    while(t--){
		int n, S;
		cin>>n>>S;
        int coins[n];
        FORSC(coins,0,n);
        sort(coins,coins+n);
		int table[S+1];

		table[0] = 0;

		for (int i=1; i<=S; i++)
			table[i] = INT_MAX;

		for (int i=1; i<=S; i++)
		{
			for (int j=0; j<n; j++)
			  if (coins[j] <= i)
			  {
				  int sub_res = table[i-coins[j]];
				  if (sub_res != INT_MAX && sub_res + 1 < table[i])
					  table[i] = sub_res + 1;
			  }
		}


		if(table[S]==INT_MAX)
			cout<<-1<<endl;
		else
			cout<<table[S]<<endl;
    }
}
