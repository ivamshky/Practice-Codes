#include <bits/stdc++.h>
using namespace std;

#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}
#define CLEAR(A) memset(A,0,sizeof(A));
using namespace std;

int getSteppingNumbers(int n, int m, int num)
{
    queue<int> Q;
    Q.push(num);
    int c=0;
    while(!Q.empty()){
		int t = Q.front();
		Q.pop();
        if(t>=n && t<=m)
			c += 1;
        if(num==0 || t>m)
			continue;

        int lstDig = t%10;

        int tA = t*10+(lstDig-1);
        int tB = t*10+(lstDig+1);

        if(lstDig==0)
			Q.push(tB);
		else if(lstDig==9)
			Q.push(tA);
		else{
			Q.push(tA);
			Q.push(tB);
		}
    }
    return c;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
		int l, r, count=0;
		cin>>l>>r;
        for(int i=0;i<=9;++i)
			count += getSteppingNumbers(l,r,i);
		cout<<count<<endl;
    }
	return 0;
}
