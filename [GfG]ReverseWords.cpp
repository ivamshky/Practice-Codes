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
		string s;
		string cur="";
		cin>>s;
		reverse(s.begin(),s.end());
		for(int i=0;i<s.length();i++){

			if(s[i]!='.'){
				cur = s[i]+cur;
			}
			else{
				cout<<cur<<".";
				cur="";
			}
		}
		cout<<cur<<endl;
    }
	return 0;
}
