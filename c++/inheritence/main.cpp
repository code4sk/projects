#include <iostream>

using namespace std;

class base
{
public:
    char name[21];
    int n;
public:
    void get();
    void display();
};
class der : private base
{
    int k;
    void show();
};
int main()
{
    der a;
    a.get();
    a.display();
    return 0;
}
void base ::get()
{
    cout<<"Enter the name"<<endl;
    cin>>name;
    cout<<"Enter the value of N"<<endl;
    cin>>n;
}
void base ::display()
{
    cout<<"Name:"<<ends<<name;
    cout<<endl<<"N:"<<ends<<n;
}
void der ::show()
{
    cout<<"Name:"<<endl<<name;
    cout<<endl<<"N:"<<endl<<n;
}
