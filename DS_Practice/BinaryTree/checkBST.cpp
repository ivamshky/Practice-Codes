#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
int isBSThelper(node *root, int min, int max){
    if(!root) return 1;

    if(root->data < min || root->data>max){
        return 0;
    }

    return isBSThelper(root->left, min, root->data-1) &&
            isBSThelper(root->right, root->data+1, max);
}

bool isBST(node *root, node *l = NULL, node *r = NULL){
    if(!root)
        return true;
    if(l!=NULL && root->data <= l->data)
        return false;
    if(r!=NULL && root->data >= r->data)
        return false;
    return isBST(root->left, l, root) and
            isBST(root->right, root, r);
}

node* newNode(int data)
{
  node* tmp = (node*)malloc(sizeof(node));
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
 
  return (tmp);
}
 
int main()
{
  struct node *root = newNode(3);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
 
    if(isBST(root))
    printf("Is BST\n");
    else
    printf("Not a BST\n");
    
    return 0;
}  