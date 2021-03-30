#include <iostream>

using namespace std;

struct node{
    int val = -1;
    node *left=NULL, *right=NULL;
};

void insertInBST(node *&root, int el){
    if(root == NULL){
       node *temp = new node;
       temp->val = el;
       root = temp;
//       cout<<root->val<<endl;
       return;
    }
    node *p = root, *parent = root;
    while(p){
        parent = p;
        if(p->val < el){
            p = p->right;
        } else {
            p = p->left;
        }
    }
    node *temp = new node;
    temp->val = el;
    if(parent->val < el){
        parent->right = temp;
    } else {
        parent->left = temp;
    }
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;


    while (current && current->left != NULL)
        current = current->left;

       return current;
}

node* deleteElement(node* root, int val)
{
    if (root == NULL) return root;

    if (val < root->val)
        root->left = deleteElement(root->left, val);

    else if (val > root->val)
        root->right = deleteElement(root->right, val);


    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        node* temp = minValueNode(root->right);

        root->val = temp->val;

        root->right = deleteElement(root->right, temp->val);
    }
    return root;
}


void printInorder(node *p){
    if(p == NULL){
        return;
    }
    if(p->left){
    printInorder(p->left);
    }
    cout<<p->val<<" ";
    if(p->right){
    printInorder(p->right);
    }
}

int main()
{
    int arr[] = {1, 53, 54, 7, 43, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    node *root = NULL;
    cout<<"Original list is :\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        insertInBST(root, arr[i]);
    }
    cout<<"\n";
    cout<<"\nInorder traversal before deletion\n";
    printInorder(root);
    cout<<endl;
    cout<<"\nDeleting element : "<<arr[n/2]<<endl;
    root = deleteElement(root, arr[n/2]);
    cout<<"\nInorder traversal after deletion\n";
    printInorder(root);
    cout<<endl;
    return 0;
}
