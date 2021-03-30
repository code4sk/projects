#include <bits/stdc++.h>

using namespace std;

struct node {
    char key;
    vector<node *> next;
    bool isLeaf = false;
};

void search(string str, node *root){
    node *p = root;
    cout<<endl;
    for(int i=0;i<str.length();i++){
        p = root;
        int j = i;

        while(1){
            int flag = 0;
            if(p->isLeaf){
                cout<<str.substr(i, j - i)<<"\n";
            }
            for(auto itr=p->next.begin(); itr != p->next.end(); itr++){
                auto it = *itr;
                if(j >= str.length()){
                    break;
                }
                if(it->key == str[j]){
                    j++;
                    p = it;
                    flag = 1;
                    break;
                }
            }
            if(j >= str.length()){
                break;
            }
            if(flag == 0){
                break;
            }
        }
    }
}

void traverse(node * p){
    for(auto itr = p->next.begin(); itr != p->next.end(); itr++){
        auto it = *itr;
        if(it->isLeaf){
            cout<<"*";
        }
        cout<<it->key<<" ";
        traverse(it);
    }
}

int main()
{
    string str = "hello my name is shubham kapoor";
    vector <string> patterns{"el", "count", "ham", "shubham"};
    int n = patterns.size();
    node * root = new node;
    node *p = root;
    for(int i=0;i<n;i++){
        p = root;
        for(int j=0;j<patterns[i].length();j++){
            int flag = 0;
            for(auto itr=p->next.begin();itr != p->next.end(); itr++){
                auto it = *itr;
                if(it->key == patterns[i][j]){
                    p = it;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                node *temp = new node;
                temp->key = patterns[i][j];
                p->next.push_back(temp);
                p = temp;
            }
        }
        p->isLeaf = true;
    }
    traverse(root);
    search(str, root);
    return 0;
}
