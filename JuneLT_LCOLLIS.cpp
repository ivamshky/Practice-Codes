#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
string S[15];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int boys,girls;
        cin>>boys>>girls;
        for(int i=0;i<boys;i++)
            cin>>S[i];
        int res=0;
        for(int k=0;k<boys;k++){
            for(int i=k+1;i<boys;i++){
                for(int j=0;j<girls;j++){
                    if(S[k][j]=='1' && S[i][j]=='1')
                        res+=1;
                }
            }
        }


        cout<<res<<endl;
    }
}
