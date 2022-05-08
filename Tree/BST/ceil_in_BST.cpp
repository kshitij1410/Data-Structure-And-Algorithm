#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *lchild, *rchild;

    Node(int data)
    {
        this->data = data;
        lchild = rchild = NULL;
    }
};

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->lchild);
    cout << root->data << " ";
    inOrder(root->rchild);
}

//Method1 - perform any traversal and find optimal solution //Time-O(N) and space-O(N) 

//Method2 -efficient solution O(H) and space-O(1)
struct Node *ceil_in_bst1(struct Node *root, int x)
{
    struct Node* res=NULL;

    while(root!=NULL)
    {
        if(root->data==x) return root;
        else if(root->data<x)
        {
            //move towards right
           
            root=root->rchild;
        }
        else{
             //move towards left
              res=root;
            root=root->lchild;
        }
    }
    return res;
} 


int main()
{
    struct Node *root = new Node(10);
    root->lchild = new Node(5);
    root->rchild = new Node(15);
    // root->lchild->lchild = new Node(3);
    root->rchild->lchild = new Node(12);
    root->rchild->rchild = new Node(30);
    // root->rchild->lchild->lchild = new Node(16);
    inOrder(root);
    cout << endl;
    struct Node *ans =ceil_in_bst1(root,40);
    cout<<ans->data;
    cout << endl;
    return 0;
}