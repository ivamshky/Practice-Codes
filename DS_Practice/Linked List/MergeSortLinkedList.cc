#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;

	Node(int d): data(d){ next = NULL;}
};

Node *SortedMerge(Node *a, Node *b);

void FrontBackSplit(Node *head, Node **firstHalf, Node **secondHalf);

void MergeSort(Node **head_ref)
{
    Node *head = *head_ref;
    Node *a, *b;
    if(head==NULL || head->next==NULL)
		return;
	FrontBackSplit(head,&a,&b);

	MergeSort(&a);
	MergeSort(&b);

	*head_ref = SortedMerge(a,b);
}

Node *SortedMerge(Node *a, Node *b)
{
	Node *res = NULL;
    if(a==NULL)
		return b;
	else if(b==NULL)
		return a;

    if(a->data <= b->data){
		res = a;
		res->next = SortedMerge(a->next,b);
    }
    else{
		res = b;
		res->next = SortedMerge(a,b->next);
    }
    return res;
}

void FrontBackSplit(Node *head, Node **first_half, Node **sec_half)
{
    Node *slow_ptr, *fast_ptr;
    if(head == NULL||head->next==NULL){
		*first_half = head;
		*sec_half = NULL;
    }
    else{
		slow_ptr = head;
		fast_ptr = head->next;
		while(fast_ptr!=NULL){
			fast_ptr = fast_ptr->next;
			if(fast_ptr!=NULL){
				fast_ptr = fast_ptr->next;
				slow_ptr = slow_ptr->next;
			}
		}

		*first_half = head;
		*sec_half = slow_ptr->next;
        slow_ptr->next = NULL;
    }
}

void printList(struct Node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}

void push(Node **head_ref, int d)
{
	Node *new_node = new Node(d);
	new_node->data  = d;

	new_node->next = (*head_ref);
	(*head_ref)    = new_node;
}

int main()
{
	Node* res = NULL;
	Node* a = NULL;
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);

	/* Sort the above created Linked List */
	MergeSort(&a);

	cout<<"\n Sorted Linked List is: \n";
	printList(a);
	return 0;
}
