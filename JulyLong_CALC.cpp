#include <bits/stdc++.h>
typedef unsigned long long int LL;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    int t;
    //freopen("CALC.in","r",stdin);
    //freopen("CALC2.out","w",stdout);
    cin>>t;
    while(t--){
		LL N,B,m=0,a,b,n=0;
		cin>>N>>B;
		b = N/B;
		a = N%B;
		if(N<=B)
			m = 0;
		else if(B==1){
			if(N%2!=0){
				m = (N/2)*(N/2 + 1);
			}
			else
				m = (N/2)*(N/2);
		}
		else if(N<=B*2){
			m = N-B;
		}
		else{
			/*while(b>=1){
				m = max(m,a*b);
				a+=B;
				b-=1;
			}*/
			n = b/2;
			m = (a+n*B)*(b-n);
		}
		cout<<m<<endl;
    }
    return 0;
}
