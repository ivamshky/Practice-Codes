#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
    int n1,n2,n3,m=0;
    cin>>n1>>n2>>n3;
    map<int,int> M;
    for(int i=0;i<n1+n2+n3;i++){
		int a;
		cin>>a;
		M[a]+=1;
    }

    map<int,int>::iterator it;
    for(it=M.begin();it!=M.end();++it){
		if(it->second >=2)
			m++;
    }
    cout<<m<<endl;
    for(it=M.begin();it!=M.end();++it){
		if(it->second >=2)
			cout<<it->first<<endl;
    }
	return 0;
}
