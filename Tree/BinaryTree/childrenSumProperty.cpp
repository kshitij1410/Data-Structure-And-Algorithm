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

//check a children sum is equal to their parent or not
bool isChildrenEqualToParent(struct Node *root){

    //base case
    if(root==NULL) return true;
    if(root->lchild==NULL and root->rchild==NULL) return true;

    int sum=0;
    if(root->lchild) sum+=root->lchild->data;
    if(root->rchild) sum+=root->rchild->data;

    return (root->data==sum and isChildrenEqualToParent(root->lchild) and isChildrenEqualToParent(root->rchild));

}

int main()
{
    struct Node *root = new Node(10);
    root->lchild = new Node(20);
    root->rchild = new Node(30);
    root->lchild->lchild = new Node(40);
    root->lchild->rchild = new Node(50);
    root->rchild->rchild = new Node(70);
    bool ans=isChildrenEqualToParent(root);
   cout<<ans<<" "; 

   
    

    return 0;
}