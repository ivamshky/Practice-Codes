#include <iostream>
#include <stack>
using namespace std;

void printNGE(int arr[], int n)
{
    stack<int> st;
    st.push(arr[0]);
	int el, next = -1;
    for(int i=1;i<n;i++){
		next = arr[i];
		if(!st.empty()){
			el = st.top();
			st.pop();
			while(el < next){
				cout<<el<<"-->"<<next<<endl;
				if(!st.empty()){
					el = st.top();
					st.pop();
				}
				else
					break;
			}
			if(el>next)
				st.push(el);
		}
		st.push(next);
    }

    while(!st.empty()){
		cout<<st.top()<<"-->"<<-1<<endl;
		st.pop();
    }
}

int main()
{
	int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
