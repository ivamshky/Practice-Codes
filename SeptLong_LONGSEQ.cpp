#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ones = count(s.begin(),s.end(),'1');
        int zeroes = count(s.begin(),s.end(),'0');
        if(ones==1 || zeroes==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
