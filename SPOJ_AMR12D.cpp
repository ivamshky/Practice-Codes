#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
		string S;
        cin>>S;
        int i=0,j=S.size()-1,f=1;
        while(i<=j){
			if(S[i]!=S[j]){
				f=0;
				break;
			}
			i++;
			j--;
        }
        f==1?cout<<"YES\n":cout<<"NO\n";
    }
	return 0;
}
