#include <iostream>
using namespace std;
#define MAX 1000
class Stack{
    int top;
public:
    int a[MAX];
    Stack(): top(-1){ }
    bool push(int x);
    int pop();
    bool isEmpty();
    int peek();
};

int Stack::peek(){
    if(top<0){
        cout<<"Empty Stack!"<<endl;
        return -1;
    }
    else{
        return a[top];
    }
}

bool Stack::push(int x){
    if(top>=MAX){
        cout<<"Stack Overflow"<<endl;
        return false;
    }
    else{
        a[++top] = x;
        return true;
    }
}

int Stack::pop(){
    if(top<0){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else{
        int x = a[top--];
        return x;
    }
}

bool Stack::isEmpty(){
    return (top<0);
}

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while(s.peek()!=-1)
        cout<<s.pop()<<" top of the stack"<<endl;
    return 0;
}