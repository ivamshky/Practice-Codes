#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct node{
    node *left, *right;
    int key;
};

node *newNode(int item){
    node *tmp = (node*)malloc(sizeof(node));
    tmp->key = item;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void inorder(node *root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

node *insert(node *root, int key){
    if(root == NULL){
        return newNode(key);
    }
    if(key < root->key)
        root->left = insert(root->left, key);
    else if(key > root->key)
        root->right = insert(root->right, key);
    
    return root;
}

node *search(node *root, int key){
    if(root == NULL || root->key == key){
        return root;
    }

    if(key > root->key)
        return search(root->right, key);

    return search(root->left, key);
}

node *minValueNode(node *root){
    node *curr = root;
    while(curr->left!=NULL){
        curr = curr->left;
    }

    return curr;
}

node *deleteNode(node *root, int key){
    if(root == NULL) return root;

    if(key < root->key){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->key){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left==NULL){
            node *tmp = root->right;
            free(root);
            return tmp;
        }
        else if(root->right==NULL){
            node *tmp = root->left;
            free(root);
            return tmp;
        }
        
        node *inorderSuccessor = minValueNode(root->right);
        root->key = inorderSuccessor->key;

        root->right = deleteNode(root->right, inorderSuccessor->key);
    }

    return root;
}

int main(){    
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    node *n = search(root, 80);
    if(n)
        cout<<"Found"<<endl;
    else 
        cout<<"Not Found"<<endl;

    cout<<"\nDelete 20\n";
    root = deleteNode(root, 20);
    cout<<"Inorder traversal of the modified tree \n";
    inorder(root);
    cout<<"\nDelete 50\n";
    root = deleteNode(root, 50);
    cout<<"Inorder traversal of the modified tree \n";
    inorder(root);
    return 0;
}