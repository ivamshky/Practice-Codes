#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
    Node(int d): data(d){
    	left = right = NULL;
    }
};


Node* insertNode(Node *root, int data)
{
    Node *newNode = new Node(data);
    if(!root){
		return newNode;
    }

    if(root->data > data){
		root->left = insertNode(root->left, data);
    }
    else if(root->data < data){
		root->right = insertNode(root->right, data);
    }
	return root;
}

Node* bst(int Ar[], int n)
{
	Node *root = NULL;
    for(int i=0;i<n;++i){
		root = insertNode(root, Ar[i]);
    }
    return root;
}

Node* kth_smallest_Node(Node *root, int k)
{
    stack<Node*> S;
    Node *pCrawl = root;
    while(pCrawl){
		S.push(pCrawl);
		pCrawl = pCrawl->left;
    }

    while(pCrawl = S.top()){
		S.pop();
		if(!--k){
			break;
		}
		if(pCrawl->right){
			pCrawl = pCrawl->right;
			while(pCrawl){
				S.push(pCrawl);
				pCrawl = pCrawl->left;
			}
		}
    }
    return pCrawl;
}

int main()
{
	int ele[] = { 20, 8, 22, 4, 12, 10, 14 };
    Node *root = bst(ele, 7);
    int k = 3;
    Node *kNode = kth_smallest_Node(root, k);
    if(kNode)
		cout<<kNode->data<<endl;
	else
		cout<<"Not Found"<<endl;
}
