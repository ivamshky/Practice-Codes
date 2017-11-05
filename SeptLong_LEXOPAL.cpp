#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int sz = s.size();
    if(sz%2){
        if(s[sz/2]=='.')
            s[sz/2]='a';
    }
    for(int i=0;i<sz/2;i++){
        if(s[i]=='.' && s[sz-1-i]=='.'){
            s[i]=s[sz-1-i]='a';
        }
        else if(s[i]=='.' && s[sz-1-i]!='.'){
            s[i]=s[sz-1-i];
        }
        else if(s[i]!='.' && s[sz-1-i]=='.'){
            s[sz-1-i]=s[i];
        }
        else if(s[i]!=s[sz-1-i]){
            cout<<"-1"<<endl;
            return;
        }
    }
    cout<<s<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
