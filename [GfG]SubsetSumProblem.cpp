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

bool isPartition(vector<int>& A, int n)
{
    int sum=0;
    for(int i: A)
		sum+=i;

	if(sum%2){
		return false;
	}

//	bool part[sum/2+1][n+1];
	vector< vector<bool> >part(sum/2+1, vector<bool>(n+1));
// Initialize
	for(int i=0;i<=n;i++)
		part[0][i]=true;

	for(int i=1;i<=sum/2;i++)
		part[i][0] = false;
//Initialize end

    for(int i=1;i<=sum/2;i++){
		for(int j=1;j<=n;j++){
			part[i][j] = part[i][j-1];

			if(i >= A[j-1]){
				part[i][j] = part[i][j] || part[i-A[j-1]][j-1];
			}
		}
    }
    return part[sum/2][n];
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

		if(isPartition(A,n))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
    }
	return 0;
}
