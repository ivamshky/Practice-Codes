#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin>>N;
	vector<long long int> A(N);
	//vector<int> B(N);
	long long int a=0,b=0;
	//long int sum=0,l=0;
	for(int i=0;i<N;i++){
		int j,k;
		cin>>j>>k;
		a+=j,b+=k;
		A[i]=a-b;
		//cout<<A[i]<<endl;
	}
	sort(A.begin(),A.end());
	if(abs(A[0])<=A[N-1])
		cout<<"1 "<<A[N-1]<<endl;
	else
		cout<<"2 "<<abs(A[0])<<endl;
	return 0;
}
