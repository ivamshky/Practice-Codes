#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <queue>
using namespace std;

struct node{
    int data;
    node *left, *right;
};

node *newNode(int data) {
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}

int height(node *root){
    if(root==NULL)
        return 0;
    int leftHeight = 1+height(root->left);
    int rightHeight = 1+height(root->right);
    return max(leftHeight,rightHeight);
}

void postorder(node *root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void preorder(node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
// Level Order without a Queue
void printGivenLevel(node *root, int l){
    if(root == NULL)
        return;
    if(l==1)
        cout<<root->data<<" ";
    else if(l > 1){
        printGivenLevel(root->left,l-1);
        printGivenLevel(root->right,l-1);
    }
}

void levelOrder(node *root){
    int h = height(root);
    for(int i=1;i<=h;i++){
        cout<<"Level "<<i<<":"<<endl;
        printGivenLevel(root,i);
        cout<<endl;
    }
}
// levelorder without a Queue End.

// Levelorder using BFS [Using a Queue]
void BFS(node *root){
    queue<node*> Q;
    node *tmp = root;
    while(tmp){
        cout<<tmp->data<<" ";
        if(tmp->left)
            Q.push(tmp->left);
        if(tmp->right)
            Q.push(tmp->right);
        
        tmp = Q.front();
        Q.pop();
    }
}
// BFS END

int main(){
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"preOrder: "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"InOrder: "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"PostOrder: "<<endl;
    postorder(root);
    cout<<endl;

    cout<<"Levelorder: "<<endl;
    levelOrder(root);
    cout<<endl;

    cout<<"LevelOrder using BFS: "<<endl;
    BFS(root);
    cout<<endl;

    return 0;
}