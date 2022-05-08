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

void inOrder(struct Node*root){
    if(root==NULL) return;

    inOrder(root->lchild);
    cout<<root->data<<" ";
    inOrder(root->rchild);
}

int main()
{
    struct Node *root = new Node(15);
    root->lchild = new Node(5);
    root->rchild = new Node(20);
    root->lchild->lchild = new Node(3);
    root->rchild->lchild = new Node(18);
    root->rchild->rchild = new Node(80);
    root->rchild->lchild->lchild = new Node(16);
    inOrder(root);
    return 0;
} 