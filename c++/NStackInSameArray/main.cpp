#include <iostream>

using namespace std;

class Stack{
    int total = -1;
    int n = 10001;
    int arr[10001];
    int top[100];

public:

    Stack(int k){
        total = k;
        int initial = -1;
        int s = n/total;
        for(int i=1;i<=k;i++){
            top[i] = initial;
            initial += s+1;
        }
    }

    void push(int a, int k){
        cout<<"\nPushing "<<a<<" in Stack "<<k<<"\n";
        arr[++top[k]] = a;
        displayResult(k);
    }
    int pop(int k){
        int initial = 0;
        int s = n/total;
        for(int i=2;i<=k;i++){
            initial += s;
        }
        if(top[k] < initial){
            cout<<"\nError\n";
            return -1;
        }
        cout<<"\nPopping top element from Stack "<<k<<"\n";;
        int val = arr[top[k]];
        top[k]--;
        displayResult(k);
        return val;
    }
    int peek(int k){
        int initial = 0;
        int s = n/total;
        for(int i=2;i<=k;i++){
            initial += s;
        }
        if(top[k] < initial){
            cout<<"\nError\n";
            return -1;
        }
        cout<<"\nPeeking top element from Stack "<<k<<"\n";
        displayResult(k);
        return arr[top[k]];

    }
    void displayResult(int k){
        cout<<"Stack "<<k<<" elements are:\n";
        int initial = 0;
        int s = n/total;
        for(int i=2;i<=k;i++){
            initial += s+1;
        }
        for(int i=initial;i<=top[k];i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl<<endl;
    }
};

int main()
{
    Stack s(5);


    s.push(45, 1);
    s.push(7, 1);
    s.push(17, 1);
    s.pop(1);
    s.peek(1);


    s.push(6, 2);
    s.push(81, 2);
    s.push(3, 2);
    s.pop(2);
    s.peek(2);


    return 0;
}
