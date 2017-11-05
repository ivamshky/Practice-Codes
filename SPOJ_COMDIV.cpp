#include <bits/stdc++.h>
using namespace std;

long long int num_div(int a)
{
	long long int n = 1;
	long int p=0;
    for(int i=2;i*i<=a;++i){
		p=0;
		while(a%i==0){
			a = a/i;
			p++;
		}
		n = (p+1)*n;

    }
    if(a>1)
		n*=2;
    return n;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--){
		int a,b;
		scanf("%d%d",&a,&b);
		long long int g = __gcd(a,b);
		//cout<<_g<<endl;
		long long int com_div = num_div(g);
		if(g==1)
			printf("1\n");
		else
			printf("%lld\n",com_div);
    }
    return 0;
}
