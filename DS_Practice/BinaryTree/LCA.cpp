#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

node* newNode(int data)
{
  node* tmp = (node*)malloc(sizeof(node));
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
 
  return (tmp);
}

node *lca(node *root, int n1, int n2){
    if(!root) return NULL;

    if(root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
    if(root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
    
    return root;
}

int main()
{
    node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    return 0;
}  