#include <iostream>
#include <limits.h>
using namespace std;

class twoStacks{
    int *arr;
    int size;
    int top1, top2;
public:
    twoStacks(int s): size(s),top1(-1),top2(s){
        arr = new int[size];
    }
    void push1(int x);
    void push2(int x);
    void pop1();
    void pop2();
};

void twoStacks::push1(int x){
    if(top2-top1>1){
        arr[++top1] = x;
    }
    else{
        cout<<"Stack Overflow"<<endl;
        return;
    }
}

void twoStacks::push2(int x){
    if(top2-top1>1){
        arr[--top2] = x;
    }
    else{
        cout<<"Stack Overflow"<<endl;
        return;
    }
}

int twoStacks::pop1(){
    if(top1<0){
        return INT_MIN;
    }
    else{
        int x = arr[top1--];
        return x;
    }
}

int twoStacks::pop2(){
    if(top2 >= size){
        return INT_MIN;
    }
    else{
        int x = arr[top2++];
        return x;
    }
}

int main(){
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout<<"Popped "<<ts.pop1()<<" from Stack_1"<<endl;
    ts.push2(40);
    cout<<"Popped "<<ts.pop2()<<" from Stack_2"<<endl;
    return 0;
}