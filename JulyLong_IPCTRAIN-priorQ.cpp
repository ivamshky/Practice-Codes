#include <bits/stdc++.h>
using namespace std;

struct trainer {
	int day,lect,sad;
};

bool comp_sad(trainer a,trainer b){
	return a.sad<b.sad;
}

bool comp_day(trainer a,trainer b){
	return a.day<b.day;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
		int n,days;
		cin>>n>>days;
		long long int total=0, sum=0;
		priority_queue<trainer,vector<trainer>,function<bool(trainer,trainer)> > P(comp_sad);
        trainer arr[n];
        for(int i=0;i<n;i++){
			cin>>arr[i].day>>arr[i].lect>>arr[i].sad;
			total += arr[i].sad*(long long)arr[i].lect;
        }
        sort(arr,arr+n,comp_day);
		int i=0;
        for(int k=1;k<=days;k++){
            while(i<n && arr[i].day==k){
				P.push(arr[i]);
				i++;
            }
            if(P.size()==0) continue;
            sum += P.top().sad;
            trainer a = P.top();
            P.pop();
            a.lect -= 1;
            if(a.lect>0)
				P.push(a);
        }
        cout<<total-sum<<endl;
    }
}
