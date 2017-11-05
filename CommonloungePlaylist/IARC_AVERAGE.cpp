#include<bits/stdc++.h>

using namespace std;
#define LL long long

LL A[10002];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
    LL N;
    cin>>N;
   // LL A[N+1];
    //A[0]=-1;
    for(int i=1;i<=N;i++)
		cin>>A[i];
    sort(A+1,A+N+1);
    LL cnt=0;
    int p1,p2;

    for(int i=1;i<=N;i++){
        p1=i;
        p2=i;
        bool found = false;
        while(p1>0 && p2<=N && !found){
			if((A[p1]+A[p2]==2*A[i]) && p1!=p2 && (p1!=i || p2!=i)){
				cnt++;
				found=true;
			}
			else{
				if(A[i]==A[i-1]){
					cnt++; found=true;
				}
				else if(A[i]==A[i+1]){
					cnt++; found=true;
				}
			}

			if(A[p1]+A[p2] > 2*A[i]) p1--;
			else p2++;
        }
    }
    cout<<cnt<<endl;
}
