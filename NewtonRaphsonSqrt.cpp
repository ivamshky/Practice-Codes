#include <iostream>
using namespace std;
double square_root(int n){
    double e = 0.00001;
    double x = n, y=1;

    while(x-y > e){
        x = (x+y)/2;
        y = n/x;
    }
    return y;
}

int main(){
    int n;
    cin>>n;
    cout<<square_root(n)<<endl;
    return 0;
}