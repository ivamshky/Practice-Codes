#include <bits/stdc++.h>
using namespace std;

#define FORSC(A,n1,n2) for(int i=n1;i<n2;i++){cin>>A[i];}
#define FOROUT(A,n1,n2) for(int i=n1;i<n2;i++){cout<<A[i]<<" ";}

struct minHeapNode
{
	char data;
	unsigned int freq;
	minHeapNode *left, *right;

	minHeapNode(char d, unsigned f):data(d),freq(f){
		left = right = NULL;
	}
};

struct cmp{
	bool operator()(minHeapNode *l, minHeapNode *r){
		return l->freq > r->freq;
	}
};

void printCodes(minHeapNode* root, string str)
{
    if(!root)
		return;
	if(root->data != '$'){
		cout<<str<<" ";
	}
	printCodes(root->left,str+"0");
	printCodes(root->right,str+"1");
}

void huffmanEncoding(string s, int *freq, int sz)
{
    minHeapNode *left, *right, *top;
    priority_queue<minHeapNode*, vector<minHeapNode*>, cmp> minHeap;

    for(int i=0;i<sz;++i){
		minHeap.push(new minHeapNode(s[i],freq[i]));
    }

    while(minHeap.size()!=1){
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();

		top = new minHeapNode('$',left->freq+right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
    }

    printCodes(minHeap.top(),"");
}

int main()
{
    int t;
    cin>>t;
    while(t--){
		string s;
		cin>>s;
		int sz = s.length();
		int freq[sz];
		FORSC(freq,0,sz);
        huffmanEncoding(s,freq,sz);
    }
}
