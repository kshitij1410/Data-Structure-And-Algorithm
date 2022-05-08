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



int main()
{
    struct Node *root = new Node(10);
    root->lchild = new Node(20);
    root->rchild = new Node(30);
    root->rchild->lchild = new Node(40);
    root->rchild->rchild = new Node(50);
    root->rchild->rchild->rchild = new Node(80);
    root->rchild->lchild->lchild = new Node(60);
    root->rchild->lchild->rchild = new Node(70);
    return 0;
} 