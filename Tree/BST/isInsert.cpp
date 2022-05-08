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

// Method-1st recursive approach //time-O(LOGN) and auxiliary space -0(H)
struct Node *isInsert(struct Node *root, int x)
{

    if (root == NULL)
        return new Node(x);

    // element already exist then return root
    if (root->data == x)
        return root;
    else if (root->data > x)
        root->lchild = isInsert(root->lchild, x);
    else
        root->rchild = isInsert(root->rchild, x);

    return root;
}

//Method 2nd Iterative approach //timeO(N) ans auxiliary space O(1)

struct Node *isInsert1(struct Node *root, int x)
{
   // base case
   if(root==NULL) return new Node(x);
   struct Node *curr=root,*parent;

   while(curr!=NULL)
   {
       if(curr->data==x) return root;
       else if(curr->data < x) curr=curr->rchild;
       else curr=curr->lchild;

       parent=curr;
   }

//its mean we find out location to insert
   if(parent->data < x) parent->rchild=new Node(x);
   else parent->lchild=new Node(x);

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
    cout<<endl;
    root=isInsert(root, 19);
    inOrder(root);
     cout<<endl;
    root=isInsert1(root, 19);
    inOrder(root);
    return 0;
}