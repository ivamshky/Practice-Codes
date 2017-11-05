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

int mergeArrays(int A[], int tmp[], int l, int mid, int r)
{
    int i,j,k,inv_count=0;

    i = l;
    j = mid;
    k = l;
    while((i<=mid-1)&&(j<=r)){
		if(A[i]<=A[j]){
			tmp[k++] = A[i++];
		}
		else{
			tmp[k++] = A[j++];
			inv_count = inv_count + (mid-i);
		}
    }

	while (i <= mid - 1)
		tmp[k++] = A[i++];

  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= r)
    tmp[k++] = A[j++];

  /*Copy back the merged elements to original array*/
  for (i=l; i <= r; i++)
    A[i] = tmp[i];

	return inv_count;
}

int modifiedMergeSort(int A[], int tmp[], int l, int r){
    int mid, inv_count=0;
    if(r>l){
		mid = (l+r)/2;
		inv_count = modifiedMergeSort(A,tmp,l,mid);
		inv_count += modifiedMergeSort(A,tmp, mid+1,r);

		inv_count += mergeArrays(A,tmp,l,mid+1,r);
    }
}

int getInversionCount(int A[], int n){
	int *tmp = (int *)malloc(sizeof(int)*n);

	return modifiedMergeSort(A,tmp,0,n-1);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
		int n;
		cin>>n;
		int A[n];
		FORSC(A,0,n);
        cout<<getInversionCount(A,n)<<endl;
    }
	return 0;
}
