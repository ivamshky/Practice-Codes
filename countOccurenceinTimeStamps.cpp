#include <iostream>
#include <vector>
using namespace std;

void inc(vector<int>& A, int x)
{
	if(x<10){
		A[0]++;
		A[x]++;
	}
	else{
		A[x%10]++;
		A[x/10]++;
	}
}

int main()
{
	int hh1,ss1,mm1;
	int hh2,ss2,mm2;

	cin>>hh1>>mm1>>ss1;
	cin>>hh2>>mm2>>ss2;
	vector<int> A(10);
    while(hh1<=hh2 && mm1<=mm2 && ss1<=ss2){
        inc(A,ss1);
        inc(A,mm1);
        inc(A,hh1);
//        for(auto i: A)
//			cout<<i<<" ";
        ss1++;
        if(ss1>59){
			ss1=0; mm1++;
        }
        if(mm1>59){
			mm1=0;hh1++;
        }
//        cout<<endl;
    }
    for(auto i: A)
		cout<<i<<" ";
}
