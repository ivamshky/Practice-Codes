#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class stack_two_queues{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int x);
    int pop();
};

void stack_two_queues::push(int x){
    q1.push(x);
    cout<<x<<" is pushed"<<endl;
}

int stack_two_queues::pop(){
    if(q1.size()==0)
        return -1;
    int x = q1.front();
    q1.pop();
    while(q1.size()>0){
        q2.push(q1.front());
        //cout<<q1.front()<<" is pushed to q2"<<endl;
        q1.pop();
    }

   // cout<<x<<" is popped"<<endl;
    q1.swap(q2);
    return x;
}

int main(){
    stack_two_queues s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.pop()<<" "<<s.pop()<<" "<<s.pop()<<" "<<s.pop()<<endl;
    cout<<endl;
    return 0;
}
