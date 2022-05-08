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

int height(struct Node *root){

    //base case
    if(root==NULL) return -1;

    int hl=height(root->lchild);
    int hr=height(root->rchild);

    return hl>hr?hl+1:hr+1;
}

//method 1 - o(n*n) 
//check whether is balanced or not
bool isBalancedTree(struct Node *root){

    //base case
    if(root==NULL) return true;
    if(root->lchild==NULL and root->rchild==NULL) return true;

    bool left= isBalancedTree(root->lchild);
    bool right = isBalancedTree(root->rchild);

    int hl=height(root->lchild);
    int hr=height(root->rchild);

    bool ans=abs(hl-hr) <=1 ? true:false;
  
    return left and right and ans;

}

int ishelperisBalancedTree1(struct Node *root){
    //base case
    if(root==NULL) return 0;
    

    bool left= ishelperisBalancedTree1(root->lchild);
    bool right = ishelperisBalancedTree1(root->rchild);

    bool ans=abs(left-right)+1; 
    
    return ans;
}
//method 2 -O(n)
int isBalancedTree1(struct Node *root){

   int result=ishelperisBalancedTree1(root);
     if(result<=1) return true;
     else return false;
}


int main()
{
    struct Node *root = new Node(18);
    root->lchild = new Node(4);
    root->rchild = new Node(20);
    root->lchild->lchild = new Node(40);
    root->lchild->rchild = new Node(50);
    // root->rchild->rchild = new Node(70);
    root->lchild->rchild->lchild = new Node(70);
    root->lchild->rchild->rchild = new Node(70);
     root->rchild->lchild = new Node(13);
    bool ans=isBalancedTree(root);
   cout<<ans<<" "; 
   bool result=isBalancedTree1(root);
   cout<<result<<" "; 
   

   
    

    return 0;
}