#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
int type[101][101];
int ck[6]={0};
void solve(){
    int n,c;
    int ci,winner=-1,maxscore=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ci);
        memset(ck,0,sizeof(ck));
        for(int j=0;j<ci;j++){
            scanf("%d",&c);
            ck[c-1]++;
        }
        int score = ci;
        int p=0;
        while(1){
            for(int k=0;k<6;k++){
              //  cout<<ck[k]<<" ";
                if(ck[k]>0){
                    p+=1;
                    ck[k]--;
                }
            }

       // cout<<endl;
        //cout<<"p="<<p<<endl;
            if(p==4)
                score+=1;
            else if(p==5)
                score+=2;
            else if(p==6)
                score+=4;
            else if(p<4)
                break;
            p=0;
        }
       // cout<<"score="<<score<<endl;
        if(maxscore==score)
            winner=-1;
        else if(maxscore<score){
            winner=i;
            maxscore = score;
        }

        //cout<<"winner="<<winner<<endl;
    }

    if(winner==0)
        printf("chef\n");
    else if(winner==-1)
        printf("tie\n");
    else
        printf("%d\n",winner+1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

