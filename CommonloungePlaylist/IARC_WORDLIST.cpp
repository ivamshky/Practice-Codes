#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char line[83];
set<string> cs;
int main()
{
    int n;
    cin>>n;
    getchar();
    while(n--){
		gets(line);
		int len = strlen(line);
		for(int i=0;i<len;i++){
			line[i] = tolower(line[i]);
			if(line[i]<'a' || line[i]>'z')
				line[i]=' ';
		}
		stringstream ss(line);
		string word;
		while(ss>>word){
			cs.insert(word);
		}
    }
    cout<<cs.size()<<endl;
	for(set<string>::iterator it=cs.begin();it!=cs.end();it++){
		cout<<(*it).c_str()<<endl;
	}
	return 0;
}
