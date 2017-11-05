#include<iostream>
#include<climits>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<list>

#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}

using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        FORSC(A,0,n);

        int i=-1,j=n-1, sumL=0,sumR=A[n-1],ans=-1;
        while(j-i>=2 && i<n && j>=0){

            if(sumL<sumR){
                i++;
                sumL+=A[i];
            }
            else if(sumR<sumL){
                j--;
                sumR+=A[j];
            }
            else if(sumR==sumL){
                if(j-i==2){
                    ans = (j+i)/2 + 1;
                    break;
                }
                else{
                    sumR += A[--j];
                    sumL += A[++i];
                }
            }


        }
        if(n==1)
            cout<<1<<endl;
        else
            cout<<ans<<endl;
    }
	return 0;
}
