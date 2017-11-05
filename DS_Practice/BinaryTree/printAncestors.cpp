#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <queue>
using namespace std;

struct node{
    int data;
    node *left, *right;
};

node *newnode(int data) {
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}

bool printAncestors(node *root, int key){
    if(!root) return false;
    if(root->data==key) return true;

    if(printAncestors(root->left, key) || printAncestors(root->right, key)){
        cout<<root->data<<" ";
        return true;
    }

    return false;
}

int main()
{
    node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->left->left->left = newnode(7);

    printAncestors(root, 7);
    cout<<endl;

    return 0;
}