#include<bits/stdc++.h>
using namespace std;
//#define FIN 0
int main()
{
	ios_base::sync_with_stdio(0);
	#ifdef FIN
	freopen("bookshelf_in.in","r",stdin);
	#endif
    int N,K;
    cin>>N>>K;
    vector<int> a(N);vector<int> b(N);
    multiset<int> min_q,max_q;
    for(int i=0;i<N;i++)
		cin>>a[i];
	for(int i=0;i<N;i++)
		cin>>b[i];

    if(*max_element(a.begin(),a.end()) > *max_element(b.begin(),b.end()))
		swap(a,b);
    for(int i=0;i<N;i++){
        min_q.insert(a[i]);
        max_q.insert(b[i]);
    }
    int skew = *min_q.rbegin() + *max_q.rbegin();
    int k2 = K;
    while(K--){
		int max_a = *min_q.rbegin(); min_q.erase(--min_q.end());
		int min_b = *max_q.begin(); max_q.erase(max_q.begin());
		min_q.insert(min_b); max_q.insert(max_a);
		skew = min(skew,*min_q.rbegin()+*max_q.rbegin());
    }

    swap(a,b);
    min_q.clear();
    max_q.clear();
    for(int i=0;i<N;i++){
        min_q.insert(a[i]);
        max_q.insert(b[i]);
    }
    int skew2 = *min_q.rbegin() + *max_q.rbegin();
    while(k2--){
		int max_a = *min_q.rbegin(); min_q.erase(--min_q.end());
		int min_b = *max_q.begin(); max_q.erase(max_q.begin());
		min_q.insert(min_b); max_q.insert(max_a);
		skew2 = min(skew,*min_q.rbegin()+*max_q.rbegin());
    }
    cout<<min(skew2,skew)<<endl;
    return 0;
}
