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

bool isMajor(vector<int> A, int maj_i)
{
	int c=0;
    for(int i: A){
		if(i==A[maj_i])
			c++;
    }

    if(c > A.size()/2)
		return true;
	return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> A(n);
		FORSC(A,0,n);
        int c=1, maj_i = 0;
        for(int i=1;i<n;i++){
			if(A[maj_i]==A[i])
				c++;
			else
				c--;

			if(c==0)
				maj_i=i, c=1;
        }
        if(isMajor(A,maj_i)){
			cout<<A[maj_i]<<endl;
        }
        else{
			cout<<"NO Majority Element"<<endl;
        }
	}
	return 0;
}
