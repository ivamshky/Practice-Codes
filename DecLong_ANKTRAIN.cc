#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    string seats[] = {"SU","LB","MB","UB"};
    cin>>t;
    while(t--){
        int seat;
        cin>>seat;
        if(seat%8 > 0 && seat%8 < 4){
            cout<<seat+3<<seats[seat%8]<<endl;
        }
        else if(seat%8 > 3 && seat%8<7){
            cout<<seat-3<<seats[(seat-3)%8]<<endl;
        }
        else if(seat%8 == 0)
            cout<<seat-1<<"SL"<<endl;
        else if(seat%8 == 7)
            cout<<seat+1<<"SU"<<endl;
    }
}
