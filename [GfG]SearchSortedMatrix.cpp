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
const int MAX = 100;

void binarySearch(int mat[][MAX], int i, int j_low, int j_high, int x)
{
	while(j_low<j_high){
		int j_mid = (j_high+j_low)/2;
		if(mat[i][j_mid]==x){
			cout<<"Found at ("<<i<<", "<<j_mid<<")"<<endl;
			return;
		}
		else if(mat[i][j_mid]<x){
			j_low = j_mid+1;
		}
		else
			j_high = j_mid-1;
	}

	cout<<"Not Found\n";
}

void sortedMatrixSearch(int mat[][MAX], int n, int m, int x)
{
    if(n==1){
		binarySearch(mat,0,0,m-1,x);
		return;
    }

	int i_low = 0, i_high = n-1, j_mid = m/2, i_mid;
    while(i_low+1 < i_high){
		i_mid = (i_low+i_high)/2;
        if(mat[i_mid][j_mid]==x){
			cout<<"Found at ("<<i_mid<<", "<<j_mid<<")"<<endl;
			return;
        }
        else if(mat[i_mid][j_mid] < x){
			i_low = i_mid;
        }
        else i_high = i_mid;
    }

    if(mat[i_low][j_mid]==x){
		cout<<"Found at ("<<i_low<<", "<<j_mid<<")"<<endl;
    }
    else if(mat[i_low+1][j_mid+1]==x)
		cout<<"Found at ("<<i_low+1<<", "<<j_mid+1<<")"<<endl;

	else if(x <= mat[i_low][j_mid-1])
		binarySearch(mat,i_low,0,j_mid-1,x);
	else if(x >= mat[i_low][j_mid+1] && x <= mat[i_low][m-1])
		binarySearch(mat,i_low,j_mid+1,m-1,x);
	else if(x <= mat[i_low+1][j_mid-1])
		binarySearch(mat,i_low+1,0,j_mid-1,x);
	else
		binarySearch(mat,i_low+1,j_mid+1,m-1,x);

}

int main()
{
	int n = 4, m = 5, x = 8;
    int mat[][MAX] = {{0, 6, 8, 9, 11},
                     {20, 22, 28, 29, 31},
                     {36, 38, 50, 61, 63},
                     {64, 66, 100, 122, 128}};

    sortedMatrixSearch(mat, n, m, x);
	return 0;
}
