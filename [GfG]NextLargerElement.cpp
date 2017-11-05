#include<iostream>
#include<climits>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<stack>
#include<map>
#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
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
		map<int,int> nge;
		stack<int> s;
        int el,nxt;
        s.push(A[0]);
        for(int i=1;i<n;i++){
			nxt = A[i];
			if(!s.empty()){
				el = s.top();s.pop();
                while(el<nxt){
					nge[el] = nxt;
					if(s.empty())
						break;
					el = s.top();s.pop();
                }
                if(el>nxt)
					s.push(el);
			}
			s.push(nxt);
        }

        for(int i=0;i<n;i++){
			if(nge[A[i]]){
				cout<<nge[A[i]]<<" ";
			}
			else{
				cout<<-1<<" ";
			}
        }
        cout<<endl;
    }
	return 0;
}
