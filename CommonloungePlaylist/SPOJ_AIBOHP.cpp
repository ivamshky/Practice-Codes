#include <bits/stdc++.h>

using namespace std;
string s;
int dp[6110][6110];

int getInsertions(int l, int r){
    if(l==r || l>r)
        return 0;

    if(dp[l][r] != -1)
        return dp[l][r];

    if(s[l] == s[r])
        dp[l][r] = getInsertions(l+1,r-1);
    else{
        dp[l][r] = 1+ min(getInsertions(l+1,r),getInsertions(l,r-1));
    }
    return dp[l][r];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        memset(dp,-1,sizeof(dp));
        cout<<getInsertions(0,s.length()-1)<<endl;
    }

    return 0;
}
