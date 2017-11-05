#include <iostream>
#include <algorithm>
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
    if(root == NULL)
        return 0;

    int lheight = 1+height(root->left);
    int rheight = 1+height(root->right);

    return max(lheight,rheight);
}

int diameter(node *root){
    if(root == NULL){
        return 0;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);
    
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(lheight+rheight+1, max(ldiameter,rdiameter));
}

int main(){
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"Diameter is "<<diameter(root)<<endl;
}