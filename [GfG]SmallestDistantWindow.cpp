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
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int A[26] = {0};
        int occur[26] = {0};
        int dist_count=0;
        for(int i=0;i<s.length();++i){
            if(A[s[i]-'a']==0){
                A[s[i]-'a']++;
                dist_count++;
            }
        }
        int start=0,len_win=0,min_len=INT_MAX,c=0;
        for(int i=0;i<s.length();++i){
            occur[s[i]-'a']++;
            if(occur[s[i]-'a']==1)
                c++;
            if(c==dist_count){
                while(occur[s[start]-'a']>1){
                    if(occur[s[start]-'a']>1)
                        occur[s[start]-'a']--;
                    start++;
                }
                len_win=i-start+1;
                min_len = min(len_win,min_len);
                
            }
        }
        //cout<<s.substr(start,end-start+1)<<endl;
        cout<<min_len<<endl;
    }

	return 0;
}