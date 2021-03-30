#include <iostream>

using namespace std;

class Stack{
    int arr[10001];
    int top1 = -1;
    int top2 = 10001;

public:
    void push1(int a){
        if((top2 - top1) == 1){
            cout<<"\nError\n";
            return;
        }
        cout<<"\nPushing "<<a<<" in Stack 1\n";
        arr[++top1] = a;
        displayResult1();
    }
    int pop1(){
        if(top1 == -1){
            cout<<"\nError\n";
            return -1;
        }
        cout<<"\nPopping top element from Stack 1\n";
        int val = arr[top1];
        top1--;
        displayResult1();
        return val;
    }
    int peek1(){
        if(top1 == -1){
            cout<<"\nError\n";
            return -1;
        }
        cout<<"\nPeeking top element from Stack 1\n";
        displayResult1();
        return arr[top1];

    }
    void displayResult1(){
        cout<<"Stack 1 elements are:\n";
        for(int i=0;i<=top1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl<<endl;
    }



    void push2(int a){
        if((top2 - top1) == 1){
            cout<<"\nError\n";
            return ;
        }
        cout<<"\nPushing "<<a<<" in Stack 2\n";
        arr[--top2] = a;
        displayResult2();
    }
    int pop2(){
        if(top2 == 10000){
            cout<<"\nError\n";
            return -1;
        }
        cout<<"\nPopping top element from Stack 2\n";
        int val = arr[top2];
        top2++;
        displayResult2();
        return val;
    }
    int peek2(){
        if(top2 == -1){
            cout<<"\nError\n";
            return -1;
        }
        cout<<"\nPeeking top element from Stack 2\n";
        displayResult2();
        return arr[top2];

    }
    void displayResult2(){
        cout<<"Stack 2 elements are:\n";
        for(int i=10000;i>=top2;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl<<endl;
    }

};

int main()
{
    Stack s;

    s.push1(45);
    s.push1(7);
    s.push1(17);
    s.pop1();
    s.peek1();

    s.push2(35);
    s.push2(52);
    s.push2(4);
    s.pop2();
    s.peek2();

    return 0;
}
