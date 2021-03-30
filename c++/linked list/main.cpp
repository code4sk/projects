#include <iostream>

using namespace std;

class node
{
    static node *root;
    node *link;
    char chr;
public :
    void create();
    void display();
};
node* node::root;
int main()
{
    node list;
    list.create();
    list.display();
    return 0;
}
void node::create()
{
    node *temp,*p;
    for(int i=0;i<6;i++)
    {
        temp=new node;
        temp->link=NULL;
        switch(i)
        {
            case 0 : temp->chr='g';
            break;
            case 1 : temp->chr='o';
            break;
            case 2 : temp->chr='o';
            break;
            case 3 : temp->chr='g';
            break;
            case 4 : temp->chr='l';
            break;
            case 5 : temp->chr='e';
            break;
        }
        if(root==NULL)
            root=temp;
        else
        {
            p=root;
            while(p->link)
                p=p->link;
            p->link=temp;
        }
    }
}
void node::display()
{
    node *p;
    p=root;
    while(p)
    {
        cout<<p->chr<<ends<<ends<<ends<<ends;
        p=p->link;
    }
}
