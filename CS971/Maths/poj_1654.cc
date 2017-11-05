#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int dir[10][2]={{0,0},{1,-1},{1,0},{1,1},{0,-1},{0,0},{0,1},{-1,-1},{-1,0},{-1,1}};
typedef  long long int ll;
ll cross(ll x1,ll y1,ll x2,ll y2){
	return x1*y2 - x2*y1;
}


int main()
{
	int T;
	cin>>T;
	while(T--){
		string str;
        cin>>str;
        ll len = str.size();
        ll sum,x1,y1,x2,y2;
        sum = x1 = y1 = 0;
        for(int i=0;i<len;i++){
			x2 = x1+dir[str[i]-'0'][0];
			y2 = y1+dir[str[i]-'0'][1];
			sum += cross(x1,y1,x2,y2);
			x1 = x2;
			y1 = y2;
        }
        sum += cross(0,0,x1,y1);
        sum = sum>0 ? sum:-sum;
        sum = sum;
		if(sum&1){
            printf("%I64d.5\n",sum>>1);
        }
		else printf("%I64d\n",sum>>1);

	}
	return 0;
}
