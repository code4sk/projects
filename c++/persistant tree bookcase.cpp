#include <bits/stdc++.h>
#define SIZE 2001
 
using namespace std;
 
struct node {
    int value = 0;
    node * left = NULL, *right = NULL;
    vector<short> status;
};
 
node* build(int start, int end, int m){
    if(start == end){
        node *temp = new node;
        for(int i=0;i<=m+3;i++){
            temp->status.push_back(0);
        }
        return temp;
    }
    int mid = (start + end)/2;
    node *p = new node;
    p->left = build(start, mid, m);
    p->right = build(mid+1, end, m);
    return p;
}
 
node *insert(node *p, int start, int end, int num, int m, int j){
 
    if(start > num || end < num){
        return p;
    }
 
    if(start == num && end == num){
        if(p->status[j] == 0){
            node *temp = new node;
            for(int i=0;i<=m+4;i++){
            temp->status.push_back(0);
        }
            for(int i=1;i<=m;i++){
                temp->status[i] = p->status[i];
            }
            temp->value = p->value + 1;
            temp->left = p->left;
            temp->right = p->right;
            temp->status[j] = 1;
            return temp;
        }
        return p;
    }
    int mid = (start + end)/2;
    node *n1 = insert(p->left, start, mid, num, m, j);
    node *n2 = insert(p->right, mid+1, end, num, m, j);
    int flag = 0;
    if(p->left != n1){
        flag = 1;
    }
    if(p->right != n2){
        flag = 1;
    }
    if(flag == 1){
        node *temp = new node;
        
        temp->value = n1->value + n2->value;
        temp->left = n1;
        temp->right = n2;
        return temp;
    }
    return p;
}
 
node *Delete(node *p, int start, int end, int num, int m, int j){
 
    if(start > num || end < num){
        return p;
    }
 
    if(start == num && end == num){
        // cout<<"ok";
        if(p->status[j] == 1){
            node *temp = new node;
            for(int i=0;i<=m;i++){
            temp->status.push_back(0);
        }
            for(int i=1;i<=m;i++){
                temp->status[i] = p->status[i];
            }
            temp->value = p->value - 1;
            temp->left = p->left;
            temp->right = p->right;
            temp->status[j] = 0;
            // cout<<"ok";
            return temp;
        }
        return p;
    }
    int mid = (start + end)/2;
    node *n1 = Delete(p->left, start, mid, num, m, j);
    node *n2 = Delete(p->right, mid+1, end, num, m, j);
    int flag = 0;
    // if(p->left)
    if(p->left != n1){
        flag = 1;
    }
    // if(p->right)
    if(p->right != n2){
        flag = 1;
    }
    if(flag == 1){
        // cout<<"ok";
        node *temp = new node;
        temp->value = n1->value + n2->value;
        temp->left = n1;
        temp->right = n2;
        return temp;
    }
    return p;
}
 
node *invert(node *p, int start, int end, int num, int m){
 
    if(p == NULL){
        // printf("ok %d %d\n", start, end);
    return p;}
 
    if(start > num || end < num){
        return p;
    }
 
    if(start == num && end == num){
        node *temp = new node;
        for(int i=0;i<=m;i++){
            temp->status.push_back(0);
        }
        for(int i=1;i<=m;i++){
            if(p->status[i] == 1){
                temp->status[i] = 0;
            } else {
                temp->status[i] = 1;
            }
        }
        // cout<<"done\n";
        // for(int i=1;i<=m;i++){
        //     cout<<temp->status[i]<<" ";
        // }
        // cout<<"\ndone\n";
        temp->value = m - p->value;
        temp->left = p->left;
        temp->right = p->right;
        return temp;
    }
    int mid = (start + end)/2;
    node *n1 = invert(p->left, start, mid, num, m);
    node *n2 = invert(p->right, mid+1, end, num, m);
    int flag = 0;
    // if(p->left)
    if(p->left != n1){
        flag = 1;
    }
    // if(p->right)
    if(p->right != n2){
        flag = 1;
    }
    if(flag == 1){
        node *temp = new node;
        temp->value = n1->value + n2->value;
        temp->left = n1;
        temp->right = n2;
        return temp;
    }
    return p;
}
 
void traverse(node *p, int start, int end, int m){
    if(start == end){
        cout<<start<<ends;
        for(int i=1;i<=m;i++){
            cout<<p->status[i]<<" ";
        }
        cout<<endl;
        return;
    }
    int mid = (start + end)/2;
    traverse(p->left, start, mid, m);
    traverse(p->right, mid+1, end, m);
}
 
int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    node *version[100001];
    version[0] = build(1, n, m);
    for(int z=1;z<=q;z++){
        int c;
        scanf("%d", &c);
        if(c == 1){
            int i, j;
            cin>>i>>j;
            version[z] = insert(version[z-1], 1, n, i, m, j);
            cout<<version[z]->value<<endl;
        } else if(c == 2){
            int i, j;
            cin>>i>>j;
            version[z] = Delete(version[z-1], 1, n, i, m, j);
            cout<<version[z]->value<<endl;
        } else if(c == 3){
            int i;
            cin>>i;
            version[z] = invert(version[z-1], 1, n, i, m);
            cout<<version[z]->value<<endl;
        } else {
            int k;
            cin>>k;
            version[z] = version[k];
            cout<<version[z]->value<<endl;
        }
        // traverse(version[z], 1, n, m);
    }
}