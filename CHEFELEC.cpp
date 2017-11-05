#include<bits/stdc++.h>
using namespace std;
const int MAX = 111111;
int x[MAX];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,j,k,maxdiff,ans=0;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<n;i++)
            cin>>x[i];

        for(int i=0;i<n;i=j){
            j=n-1;
            for(int k=i+1;k<n;k++)
                if(s[k]=='1') {j=k;break;}

            maxdiff = 0;
            for(int k=i+1;k<j;k++){
                maxdiff = max(maxdiff,x[k+1]-x[k]);
            }
            ans+=x[j]-x[i]-maxdiff;
            cout<<ans<<" "<<i<<" "<<j<<endl;
        }
        cout<<endl;
        cout<<ans<<endl;
    }
}
