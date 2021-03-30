#include<bits/stdc++.h>
using namespace std;


int n,m;
int pri_que[1000][1000];
int front[1000], rear[1000];


void check(int d, int p)
{
    int i,j;

    for (i = 0; i <= rear[p]; i++)
    {
        if (abs(d-p+1) <= abs(pri_que[p][i]-p+1))
        {
            for (j = rear[p] + 1; j > i; j--)
            {
                pri_que[p][j] = pri_que[p][j - 1];
            }
            pri_que[p][i] = d;
            return;
        }
    }
    pri_que[p][i] = d;
}

void BuildPriorityQueue(int n)
{
    for(int i=0;i<n;i++)
    front[i] = rear[i] = -1;
}


void InsertInPriorityQueue(int d, int p)
{
    if (rear[p] >= m - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((front[p] == -1) && (rear[p] == -1))
    {
        front[p]++;
        rear[p]++;
        pri_que[p][rear[p]] = d;
        return;
    }
    else
        check(d,p);
    rear[p]++;
}


void DeleteInPriorityQueue(int d ,int p)
{
    int i;

    if ((front[p]==-1) && (rear[p]==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }

    for (i = 0; i <= rear[p]; i++)
    {
        if (d == pri_que[p][i])
        {
            for (; i < rear[p]; i++)
            {
                pri_que[p][i] = pri_que[p][i + 1];
            }

        pri_que[p][i] = INT_MIN;
        rear[p]--;

        if (rear[p] == -1)
            front[p] = -1;
        return;
        }
    }
    printf("\n%d not found in queue to delete", d);
}


void DisplayPriorityQueue()
{
    cout<<endl;
    for(int i=0;i<n;i++){
    if ((front[i] == -1) && (rear[i] == -1))
    {
        printf("\nqueue %d is empty\n", i+1);
        return;
    }

    for (; front[i] <= rear[i]; front[i]++)
    {
        printf(" %d ", pri_que[i][front[i]]);
    }

    front[i] = 0;
        cout<<endl;
    }
}

int main()
{
    int ch;
 int d,i;
 cout<<"Enter n and m\n";
 cin>>n>>m;
 BuildPriorityQueue(n);
    printf("\n1 - Insert into queue");
    printf("\n2 - Delete from queue");
    printf("\n3 - Display queue");
    printf("\n4 - Exit");

    while (1)
    {
        printf("\nEnter your choice : ");
        cin>>ch;

        switch (ch)
        {
        case 1:
            printf("\nEnter value to be inserted and it's priority number \n");
            cin>>d>>i;
            InsertInPriorityQueue(d,i-1);
            break;
        case 2:
            printf("\nEnter value to delete and it's priority number\n");
            cin>>d>>i;
            DeleteInPriorityQueue(d,i-1);
            break;
        case 3:
            DisplayPriorityQueue();
            break;
        case 4:
            exit(0);
        default:
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}

