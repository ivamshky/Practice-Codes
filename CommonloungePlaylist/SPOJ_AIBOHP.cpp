#include <bits/stdc++.h>

using namespace std;
string s;
int dp[6110][6110];

int getInsertionsIter(int l, int r){
    int n = s.size();
    for(int i=0;i<n;++i){
        dp[i][i] = 0;
    }
    //For every string of length i
    for(int i=2; i<=n;++i){
        //Starting from Jth index
        for(int j = 0;j<n-i+1; ++j){
            int e = j+i-1; //End of string
            if(i==2 && s[j]==s[e])
                dp[j][e] = 0;
            else if(s[j]==s[e])
                dp[j][e] = dp[j+1][e-1];
            else
                dp[j][e] = 1+min(dp[j+1][e],dp[j][e-1]);
        }
    }
    return dp[0][n-1];
}

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
        memset(dp,INT_MAX,sizeof(dp));
        cout<<getInsertionsIter(0,s.length()-1)<<endl;
    }

    return 0;
}
