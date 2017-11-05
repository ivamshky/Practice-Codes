#include <iostream>
#include <cstdlib>
#include <limits.h>
using namespace std;

struct stack_node{
    int data;
    stack_node* next;
};

stack_node *new_node(int x){
    stack_node *node = (stack_node *)malloc(sizeof(stack_node));
    node->data = x;
    node->next = NULL;
    return node;
}

bool isEmpty(stack_node *head){
    return head==NULL;
}

void push(stack_node **head_ref, int x){
    stack_node *node = new_node(x);
    node->next = *head_ref;
    *head_ref = node;
    cout<<node->data<<" pushed onto the stack"<<endl;
}

int peek(stack_node *head){
    if(isEmpty(head)){
        return INT_MIN;
    }
    return head->data;
}

int pop(stack_node **head_ref){
    if(isEmpty(*head_ref)){
        return INT_MIN;
    }
    stack_node *tmp = *head_ref;
    *head_ref = (*head_ref)->next;
    int x = tmp->data;
    free(tmp);
    return x;
}

int main(){
    stack_node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    while(!isEmpty(head)){
        cout<<peek(head)<< " ";
        pop(&head);
    }
    cout<<endl;
    return 0;
}