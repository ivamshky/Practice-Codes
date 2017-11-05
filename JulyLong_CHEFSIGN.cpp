#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1,s2="";
        cin>>s1;
        long int l=0,m=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!='=')
				s2 += s1[i];
        }
       // cout<<s2<<endl;
        for(int i=0;i<s2.length();){
			l=0;
            while(s2[i]=='>')
                l++,i++;
			m = max(m,l);
			l=0;
			while(s2[i]=='<')
				l++,i++;
			m = max(m,l);

        }
        cout<<m+1<<endl;
    }
    return 0;
}
