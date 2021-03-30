#include <iostream>

using namespace std;

class Stack{
    int arr[10001];
    int top = -1;

public:
    void push(int a){
        cout<<"\nPushing "<<a<<" in Stack\n";
        arr[++top] = a;
        displayResult();
    }
    int pop(){
        if(top == -1){
            cout<<"\nError\n";
            return -1;
        }
        cout<<"\nPopping top element from Stack\n";
        int val = arr[top];
        top--;
        displayResult();
        return val;
    }
    int peek(){
        if(top == -1){
            cout<<"\nError\n";
            return -1;
        }
        cout<<"\nPeeking top element from Stack\n";
        displayResult();
        return arr[top];

    }
    void displayResult(){
        cout<<"Stack elements are:\n";
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
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
