#include<iostream>
#include<climits>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<stack>
#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		if(s.length()%2){
			cout<<"not balanced\n";
			continue;
		}
        int check=0;
        string openB = "{([";
        string closedB = "})]";
        for(int i=0;i<s.length();i++){
			if(openB.find(s[i])!=string::npos)
				check++;
			else check--;

			if(check<0)
				break;
        }
        if(check==0)
			cout<<"balanced\n";
		else
			cout<<"not balanced\n";
	}
	return 0;
}
