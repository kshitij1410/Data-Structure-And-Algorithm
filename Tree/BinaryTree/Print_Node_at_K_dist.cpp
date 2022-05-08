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

int treeHeight(struct Node *root)
{
    if (root == NULL)
        return -1;

    int hl = treeHeight(root->lchild);
    int hr = treeHeight(root->rchild);

    if (hl > hr)
        return hl + 1;
    else
        return hr + 1;
}

//print node at a distance k from root
void KthDistNode(struct Node *root, int k)
{

    if (root == NULL)
        return;

    // check k is valid input or not for a tree
    int h = treeHeight(root);

    cout << h << endl;
    
    if (h < k)
    {
        cout << "not a valid input";
        return;
    }

    queue<Node *> q;
    q.push(root);
    int count = 0;
    struct Node *curr = root;

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            curr = q.front();
            q.pop();

            if (count == k)
                cout << curr->data << " ";

            if (curr->lchild)
                q.push(curr->lchild);
            if (curr->rchild)
                q.push(curr->rchild);
        }
        count++;
    }
}

//efficent approach
void KthDistNode1(struct Node *root, int k){

  if(root==NULL) return;
  if (k==0) cout<<root->data<<" ";
 
  KthDistNode1(root->lchild,  k-1);
  KthDistNode1(root->rchild,  k-1);
 

}
int main()
{
    struct Node *root = new Node(10);
    root->lchild = new Node(20);
    root->rchild = new Node(30);
    root->lchild->lchild = new Node(40);
    root->lchild->rchild = new Node(50);
    root->rchild->rchild = new Node(70);
    int k = 2;
    KthDistNode1(root, k);

    return 0;
}