#include <iostream>
#include <algorithm>
using namespace std;
int bSearch(string &s, int l, int r, char key){
    int index = -1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(s[mid]<=key)
            r = mid-1;
        else{
            l = mid+1;
            if(index == -1 || s[index] >= s[mid])
                index = mid;
        }
    }
    return index;
}

void swap(char *a, char *b){
    if(*a==*b)
        return;
    *a^= *b;
    *b^= *a;
    *a^= *b;
}

void rev(string &s, int l, int r){
    while(l<r){
        swap(&s[l++],&s[r--]);
    }
}

bool nextPermutation(string &s){
    int len = s.length();
    int i=len-2;
    while(i>=0 && s[i]>=s[i+1])
        i--;
    if(i<0)
        return false;
    else{
        int index = bSearch(s,i+1,len-1,s[i]);
        // cout<<index<<endl;
        swap(&s[i],&s[index]);
        // cout<<s<<endl;
        rev(s,i+1,len-1);
        return true;
    }
}

int main(){
    string s;
    cin>>s;
    bool val = nextPermutation(s);
    if(!val)
        cout<<"Not possible"<<endl;
    else
        cout<<s<<endl;
    return 0;
}