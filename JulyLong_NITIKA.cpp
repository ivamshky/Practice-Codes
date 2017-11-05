#include <bits/stdc++.h>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
    int t;
    cin>>t;
    while(t--){
		string a;
		scanf("%s",&a);
		printf("%s",a);
        string name[3];
        int i=0,j=0;
        for(int i=a.find(" ",0);i!=string::npos;i=a.find(" ",i)){
			name[j++] = a.substr(0,i);
			cout<<name[j-1]<<" ";
        }
    }
}
