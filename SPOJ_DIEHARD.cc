#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--) {
		int h,a;
		cin>>h>>a;
        int t=1;
        h += 3; a += 2;
        while(1) {
			if(h>20 && a<=10) {
				h -= 17;
				a += 7;
				t += 2;
			}
			else if(h>5 && a>10) {
				h -= 2;
				a -= 8;
				t += 2;
			}
			else {
				cout<<t<<endl;
				break;
			}
        }
    }
}
