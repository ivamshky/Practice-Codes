#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    node *next;
};

node * createNode(){
    node *tmp = (node *)malloc(sizeof(node));
    tmp->next=NULL;
    return tmp;
}

// Appending node to the last
void add_to_last(node **head_ref, int data){
    node *tmp = createNode();
    tmp->data = data;
    if(*head_ref==NULL){
        *head_ref = tmp;
        return;
    }
    node *head = *head_ref;
    while(head->next!=NULL)
        head = head->next;
    head->next = tmp;
    return;
}

// Inserts after a given node in the Linked List
void insert_after(node *prev, int data){
    node *newNode = createNode();

    if(prev==NULL){
        cout<<"prev given can't be null."<<endl;
        return;
    }
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
}

// Pushes a Node into a linked list. [Adding in front]
void push(node **head_ref, int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// Searching and Deleting a Node
void delete_node(node **head_ref, int key){
    node *tmp = *head_ref;
    if(tmp != NULL && tmp->data==key){
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    node *prev;
    while(tmp!=NULL && tmp->data!=key){
        prev = tmp;
        tmp = tmp->next;
    }
    
    if(tmp==NULL) return;
    
    prev->next = tmp->next;
    free(tmp);
}

// Deleting Node at a given position `pos`
void delete_at_position(node **head_ref, int pos){
    
    if(*head_ref==NULL)
        return;
    
    node *tmp = *head_ref;
    // if head is to be deleted
    if(pos == 0){
        *head_ref = tmp->next;
        free(tmp);
        return;
    }

    // get the prev of the node to be deleted
    while(pos>2 && tmp!=NULL){
        tmp = tmp->next;
        pos--;
    }
    if(tmp==NULL || tmp->next==NULL)
        return;
    
    node *next = tmp->next;
    tmp->next = next->next;
    free(next);
}

// Prints the Linked List
void printLinkedList(node *head_ref){

    while(head_ref!=NULL){
        cout<<head_ref->data<<" ";
        head_ref = head_ref->next;
    }
    cout<<endl;
}

//Swapping two nodes with data x & y
void swap_nodes(node **head_ref, int x, int y){
    if(*head_ref==NULL)
        return;
    if(x==y) return;
    node *prevX = NULL, *prevY = NULL;
    node *currX = *head_ref, *currY = *head_ref;

    while(currX && currX->data!=x){
        prevX = currX;
        currX = currX->next;
    }

    while(currY && currY->data != y){
        prevY = currY;
        currY = currY->next;
    }
    if(currX==NULL || currY==NULL)
        return;
    if(prevX!=NULL){
        prevX->next = currY;
    }
    else
        *head_ref = currY;
    
    if(prevY!=NULL){
        prevY->next = currX;
    }
    else
        *head_ref = currX;
    node *tmp = currX->next;
    currX->next = currY->next;
    currY->next = tmp;
}

//length of the linked list
int get_length(node *head_ref){
    int l=0;
    while(head_ref!=NULL){
        l++;
        head_ref = head_ref->next;
    }
    return l;
}

// Reversing Linked List D->D->D->NULL;
void reverse(node **head_ref){
    node *prev = NULL, *curr = *head_ref, *next;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head_ref = prev;
}

// Reversing in k sized blocks
node* reverse_blocks(node *head_ref, int k){
    node *curr = head_ref, *prev = NULL, *next;
    int c = 0;
    //reverse in the block
    while(curr!=NULL && c<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        c++;
    }
    //call recursively for next block
    // next is a pointer to k+1th node.
    if(next!=NULL){
        head_ref->next = reverse_blocks(next, k);
    }

    return prev;
}

//length of linked list RECURSIVE
int get_length_recur(node *head){
    if(head==NULL)
        return 0;
    return 1+get_length_recur(head->next);
}

int main(){
    int n=5;
    int a[] = {1,2,3,4,5};
    node *head = NULL;
    for(int i=0;i<n;i++){
        push(&head,a[i]);
    }
    add_to_last(&head, 7);
    insert_after(head->next->next, 10);
    delete_node(&head, 10);
    delete_node(&head, 7);
    delete_at_position(&head,3);
    swap_nodes(&head, 5, 1);
    cout<<get_length(head)<<" "<<get_length_recur(head)<<endl;
    printLinkedList(head);
    reverse(&head);
    push(&head, 11);
    printLinkedList(head);
    head = reverse_blocks(head, 2);
    printLinkedList(head);
    return 0;
}