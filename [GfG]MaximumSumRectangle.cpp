#include <bits/stdc++.h>
using namespace std;

#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}
const int R = 1000;

int kadane(int *arr, int *start, int *fin,int n)
{
    int sum = 0, maxSum = INT_MIN;
    *fin = -1;
    int local_start = 0;
    for(int i=0;i<n;++i){
		sum += arr[i];
		if(sum<0){
			sum = 0;
			local_start = i+1;
		}
		else if(sum>maxSum){
			maxSum = sum;
			*start = local_start;
			*fin = i;
		}
    }

    if(*fin != -1)
		return maxSum;

	maxSum = arr[0];
	*start = *fin = 0;
	for(int i=1;i<n;++i){
		if(arr[i]>maxSum){
			maxSum = arr[i];
			*start = *fin = i;
		}
	}
	return maxSum;
}

int findMaxSum(int A[][R],int row,int col)
{
    int maxSum = INT_MIN;
    int tmp[row],sum,start,fin;
    for(int left = 0;left<col;++left){
		memset(tmp,0,sizeof(tmp));
		for(int right=left;right<col;++right){
            for(int i=0;i<row;++i)
				tmp[i] += A[i][right];

			sum = kadane(tmp,&start,&fin,row);

			if(sum>maxSum){
				maxSum = sum;
			}

		}
    }
    return maxSum;
}

int main()
{
    int t;
    cin>>t;
    int A[R][R];
    while(t--){
        int row,col;
        cin>>row>>col;
        //int A[row][col];
        for(int i=0;i<row;++i){
			for(int j=0;j<col;j++){
				cin>>A[i][j];
			}
        }

        cout<<findMaxSum(A,row,col)<<endl;
    }
}
