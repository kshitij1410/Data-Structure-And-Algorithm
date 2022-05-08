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

struct Node *getSucessor(struct Node *root)
{
    struct Node *curr = root;

    while (curr != NULL and curr->lchild != NULL)
    {
        curr = curr->lchild;
    }
    return curr;
}

// recursive approach //time-O(LOGN) and auxiliary space -0(H)
struct Node *isDelete(struct Node *root, int x)
{

    if (root == NULL)
        return NULL;

    if (root->data < x)
    {
        root->rchild = isDelete(root->rchild, x);
    }
    else if (root->data > x)
    {
        root->lchild = isDelete(root->lchild, x);
    }
    else
    {

        if (root->lchild == NULL)
        {
            struct Node *temp = root->rchild;
            delete root;
            return temp;
        }
        else if (root->rchild == NULL)
        {
            struct Node *temp = root->lchild;
            delete root;
            return temp;
        }
        else
        {
            // both lchild and rchild exist then calculate succesor - closet greatest value
            struct Node *suc = getSucessor(root->rchild);
            
            //replace root data with sucessor
            root->data=suc->data;

           //delete sucessor node
             root->rchild = isDelete(root->rchild,root->data);
            
        }
        
    }
    return root;
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
    cout << endl;
    root=isDelete(root,10);
     inOrder(root);
    return 0;
}