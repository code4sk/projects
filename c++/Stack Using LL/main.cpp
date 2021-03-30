#include <bits/stdc++.h>

using namespace std;

class node{
    public:
    int a;
    node *next = NULL;
    node(int a){
        this->a = a;
    }
};

class Stack{
    node *top;

public:
    Stack(){
        top = NULL;
    }
    void push(int a){
        cout<<"\nPushing "<<a<<" in Stack\n";
        node *temp = new node(a);
        if(top == NULL){
            top = temp;
        } else {
            temp->next = top;
            top = temp;
        }
        displayResult();
    }
    int pop(){
        if(top == NULL){
            cout<<"\nError\n";
            return -1;
        }
        cout<<"\nPopping top element from Stack\n";
        int val = top->a;
        node *temp = top;
        top = top->next;
        delete temp;
        displayResult();
        return val;
    }
    int peek(){
        if(top == NULL){
            cout<<"\nError\n";
            return -1;
        }
        cout<<"\nPeeking top element from Stack\n";
        displayResult();
        return top->a;

    }
    void displayResult(){
        cout<<"Stack elements are:\n";
        node *p = top;
        vector<int> v;
        while(p){
            v.push_back(p->a);
            p = p->next;
        }
        reverse(v.begin(), v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl<<endl;
    }
};

int main()
{
    Stack s;
    s.push(45);
    s.push(7);
    s.push(17);
    s.pop();
    s.peek();
    return 0;
}
