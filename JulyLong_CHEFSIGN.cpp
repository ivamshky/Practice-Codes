#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s,s2;
        cin>>s;
        long int l=0,c=0,m=0,x;
        for(int i=0;i<s.length();){
            l=0;
            if(s[i]=='='){
                while(s[i++]=='=')
                    l++;
                s.erase(i,l);
                i=l;
            }
        }
        cout<<s<<endl;
        for(int i=0;i<s.length();){
            if(s[i]=='>'){
                l=0;
                while(s[i++]=='>')
                    l++;
                m = max(m,l);
            }
            if(s[i]=='<'){
                l=0;
                while(s[i++]=='<')
                    l++;
                m = max(m,l);
            }
        }
        cout<<m<<endl;
    }
    return 0;
}
