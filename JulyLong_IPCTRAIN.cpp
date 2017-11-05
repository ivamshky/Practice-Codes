#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,days;
        cin>>n>>days;
        vector<int> sad(n),lect(n),startday(n);
        for(int i=0;i<n;i++){
			cin>>startday[i]>>lect[i]>>sad[i];
			startday[i]--;
        }
        vector<pair<int,int> > trainers;
        for(int i=0;i<n;i++){
			trainers.push_back(make_pair(sad[i],i));
        }
        sort(trainers.rbegin(),trainers.rend());
        vector<int> lectTaken(n);
        int cur_day=0;
        set<int> daySet;
        for(int i=0;i<days;i++){
			daySet.insert(i);
        }
        for(auto it:trainers){
            int lec = lect[it.second];
            for(int i=0;i<lec;i++){
				auto iter = daySet.lower_bound(startday[it.second]);
				if(iter == daySet.end())
					break;
				else{
					lectTaken[it.second]++;
					daySet.erase(iter);
				}
            }
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
			ans += (lect[i]-lectTaken[i])*(long long)sad[i];
        }
        cout<<ans<<"\n";
    }
}
