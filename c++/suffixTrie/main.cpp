#include <bits/stdc++.h>

using namespace std;

struct node{
    char key;
    vector <node *> next;
    bool isLeaf = false;
    int val = -1;
};

node * constructTrie(vector <string> v){
    node *root = new node;
    node *p;
    for(int i=0;i<v.size();i++){
        p = root;
        for(int j=0;j<v[i].length();j++){
            int flag = 0;
            for(auto itr = p->next.begin(); itr != p->next.end(); itr++){
                auto it = *itr;
                if(it->key == v[i][j]){
                    flag = 1;
                    p = it;
                    break;
                }
            }
            if(flag == 0){
                node *temp = new node;
                temp->key = v[i][j];
                p->next.push_back(temp);
                p = temp;
            }
        }
        p->isLeaf = true;
        p->val = i;
    }
    return root;
}

void traverse(node * p){
    for(auto itr = p->next.begin(); itr != p->next.end(); itr++){
        auto it = *itr;
        cout<<it->key<<" ";
        if(it->isLeaf){
            cout<<"*\n";
        }
        traverse(it);
    }
}

void noOfLeaves(node *p, int *ans){
    for(auto itr = p->next.begin(); itr != p->next.end(); itr++){
        auto it = *itr;
        if(it->isLeaf){
            *ans += 1;
            cout<<"Pos: "<<it->val<<"\n";
        }
        noOfLeaves(it, ans);
    }
}

void search(node *p, string str, int i){
    if(i == str.length()){
        int ans = 0;
        if(p->isLeaf){
            ans++;
            cout<<"Pos: "<<p->val<<"\n";
        }
        noOfLeaves(p, &ans);
        cout<<"No. of occurrence of subsring in given string: "<<ans<<endl;
        return;
    }
    for(auto itr = p->next.begin(); itr != p->next.end(); itr++){
        auto it = *itr;
        if(it->key == str[i]){
                //printf("ok");
            return search(it, str, ++i);
        }
    }
    cout<<"String not found!\n";
    return;
}

int main()
{
    string str = "Dracula";
    vector <string> v;
    int key[1024];
    int n = str.length();
    for(int i=0;i<n;i++){
        v.push_back(str.substr(i, n - i));
        key[i] = i;
    }
    node *root = constructTrie(v);
    traverse(root);
    cout<<endl;
    search(root, "a", 0);
    return 0;
}
