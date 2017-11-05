#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        double s,v;
        double prec = 0.0000001;
        cin>>s>>v;
        double t = (2*s)/(3*v);
        cout<<fixed;
        cout<<setprecision(7);
        if(t < prec)
            cout<<prec<<endl;
        else
            cout<<t<<endl;
    }
}
