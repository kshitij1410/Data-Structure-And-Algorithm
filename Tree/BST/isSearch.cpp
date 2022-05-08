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

// Method-1st recursive approach //time-O(LOGN) and auxiliary space -0(H)
bool isSearch(struct Node *root,int x){

  if(root==NULL) return false;

  if(root->data==x) return true;
  else if(root->data>x) return isSearch(root->lchild,x);
  else return isSearch(root->rchild,x);
   
}


//Method 2nd iterative approach //time-O(N) and auxiliary space -o(1);

bool isSearch1(struct Node *root,int x)
{
  //base case
  if(root==NULL) return false;
  struct Node * temp=root;

  while(temp!=NULL){
      if(temp->data==x) return true;
      else if(temp->data>x) temp=temp->lchild;
      else temp=temp->rchild;
  }
  return false;
  
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
    bool ans=isSearch(root,80);
    cout<<ans<<" ";
    bool ans1=isSearch(root,16);
     cout<<ans1<<" ";
    return 0;
} 