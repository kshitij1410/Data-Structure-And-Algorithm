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

//method-1
//efficient sol
void spiralOrderTraversal(struct Node *root){

  if(root==NULL) return;

  stack<Node*>st1;
  stack<Node*>st2;
  struct Node *temp=root;

  st1.push(root);

  while(!st1.empty() || !st2.empty()){

   //for st1 
   //traverse from left to right
    while(!st1.empty()){
     temp=st1.top();
     st1.pop();
     cout<<temp->data<<" ";

     if(temp->lchild) st2.push(temp->lchild);
     if(temp->rchild)  st2.push(temp->rchild);

    }


   //for stack2
   //traverse from right to left
   while(!st2.empty()){
     temp=st2.top();
     st2.pop();
     cout<<temp->data<<" ";

     
     if(temp->rchild)  st1.push(temp->rchild);
     if(temp->lchild) st1.push(temp->lchild);
     
    }
  }

}

//method-2
//problem is we are working two time to insert the data in stack and queue and pop it.
//not a good approach 
//queue store node in left to right fashion
//stack store node in right to left manner
void spiralOrderTraversal1(struct Node *root){

  if(root==NULL) return;

  queue<Node*>q;
  stack<int>s;
  struct Node *temp,*temp1;

  q.push(root);
  
 bool left_to_right=false;
 
  while(!q.empty() ){
    int count=q.size();
      for(int i=0;i<count;i++){
        temp=q.front();
        q.pop();
        
        if(left_to_right){
           s.push(temp->data);
          
        }
        else{
        cout<<temp->data<<" ";
        }
        if(temp->lchild!=NULL) q.push(temp->lchild);
        if(temp->rchild!=NULL) q.push(temp->rchild);

      }
      
     
      while(!s.empty()){
          cout<<s.top()<<" ";
          s.pop();
      }
      

      left_to_right=!left_to_right;
      
  }

}
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
   spiralOrderTraversal(root);
   cout<<endl;
    spiralOrderTraversal1(root);

    
    

    return 0;
}