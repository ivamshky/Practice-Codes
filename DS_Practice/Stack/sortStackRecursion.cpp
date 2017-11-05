#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
	stack<int> S;
    void sort();
};

void sortedInsert(stack<int> &S, int d)
{
    if(S.empty() || d > S.top()){
		S.push(d);
		return;
    }

    int tmp = S.top();S.pop();
    sortedInsert(S,d);
    S.push(tmp);
}

void SortedStack :: sort()
{
    if(!S.empty()){
		int tmp = S.top();S.pop();
		sort();
		sortedInsert(S,tmp);
    }
}

int main()
{
    int n;
    cin>>n;
	SortedStack stak;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		stak.S.push(x);
	}
    stak.sort();
    //Prints Stack top to down means, prints in reverse order.
    while(!stak.S.empty()){
		cout<<stak.S.top()<<endl;
		stak.S.pop();
    }

}
