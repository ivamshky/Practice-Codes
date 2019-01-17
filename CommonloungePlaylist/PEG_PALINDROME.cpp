#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int dp[3][5010];

int getInsertions() {

    for(int len = 1;len <= n;++len){
        for(int start=0; start+len-1 < n;++start){
            int l = len-1;
            if(len==1)
                dp[l][start] = 0;
            else if(s[start] == s[start+len-1]){
                if(len!=2)
                    dp[l%3][start] = dp[(l-2)%3][start+1];
                else
                    dp[l%3][start] = 0;
            }
            else
                dp[l%3][start] = 1+min(dp[(l-1)%3][start+1],dp[(l-1)%3][start]);
        }
    }
    return dp[(n-1)%3][0];
}

int main() {

    cin>>n;
    cin>>s;
//    memset(dp,INT_MAX,sizeof(dp));
    cout<<getInsertions()<<endl;


    return 0;
}

