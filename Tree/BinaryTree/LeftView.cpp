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

//iterative solution
void leftView(struct Node *root){

    if(root==NULL) return;
    queue<Node*>q;
    q.push(root);
    struct Node *temp=root;
     
    while(!q.empty()){
     temp=q.front();
     cout<<temp->data<<" ";
     int size=q.size();

     for(int i=0;i<size;i++){
       temp=q.front();
       q.pop();

       if(temp->lchild) q.push(temp->lchild);
       if(temp->rchild) q.push(temp->rchild);
     }
    }
}

int main()
{
    struct Node *root = new Node(10);
    root->lchild = new Node(20);
    root->rchild = new Node(30);
    root->lchild->lchild = new Node(40);
    root->lchild->rchild = new Node(50);
    root->rchild->rchild = new Node(70);
   

    leftView(root);
    

    return 0;
}