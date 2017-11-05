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

int bSearch(string &s, int l, int r, int key)
{
	int index = -1;
	while(l<=r){
		int mid = (l+r)/2;
		if(s[mid]<=key){
			r = mid-1;
		}else{
			l = mid+1;
			if(index==-1 || s[index]>=s[mid])
				index = mid;
		}
	}
	return index;
}

void rev(string &s, int l, int r){
	while(l<r){
		swap(s[l++],s[r--]);
	}
}

bool nextpermutation(string &s){
	int len = s.length();
	int i = len-2;
	while(i>=0 && s[i]>=s[i+1])
		--i;
	if(i<0) return false;
	else{
		int index = bSearch(s,i+1,len-1,s[i]);
		swap(s[i],s[index]);
		rev(s,i+1,len-1);
		return true;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
//		bool val = next_permutation(s.begin(),s.end());
		bool val = nextpermutation(s);
		if(val)
			cout<<s<<endl;
		else
			cout<<"not possible"<<endl;
	}

	return 0;
}
