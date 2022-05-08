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

//method1 O(H) and space -O(n)
struct Node *floor_in_bst(struct Node *root, int x)
{

    if (root == NULL)
        return NULL;

    stack<Node *> s;
    s.push(root);

    if (root->data < x)
    {
        struct Node *temp = floor_in_bst(root->rchild, x);
        if(temp!=NULL) return temp;
        else return root;
    }

    else if (root->data > x)
    {
        struct Node *temp = floor_in_bst(root->lchild, x);
        if (temp == NULL)
        {
            if (x > root->data)
                return root;
            else
            {
                while (!s.empty())
                {
                    struct Node *curr = s.top();
                    s.pop();
                    if (curr->data < x)
                    {
                        return curr;
                    }
                }
                return NULL;
            }
        }
        else
        {
            return temp;
        }
    }
    else
    {
        return root;
    }
}


//efficient solution O(H) and space-O(1)
struct Node *floor_in_bst1(struct Node *root, int x)
{
    struct Node* res=NULL;

    while(root!=NULL)
    {
        if(root->data==x) return root;
        else if(root->data<x)
        {
            res=root;
            root=root->rchild;
        }
        else{
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
    struct Node *ans =floor_in_bst1(root,19);
    cout<<ans->data;
    cout << endl;
    return 0;
}