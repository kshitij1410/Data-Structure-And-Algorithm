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

int height(struct Node *root)
{

    // base case
    if (root == NULL)
        return -1;

    int hl = height(root->lchild);
    int hr = height(root->rchild);

    return hl > hr ? hl + 1 : hr + 1;
}

//perform level order traversal and find max size in a level --iterative solution
int maxWidthofBt(struct Node *root)
{

    if (root == NULL)
        return 0;

    queue<Node *> q;
    q.push(root);
    int ans = 0;
    struct Node * curr=root;
    while (!q.empty())
    {

        int size = q.size();
        ans = max(ans, size);
        for (int i = 0; i < size; i++)
        {
            curr=q.front();
            q.pop();

            if(curr->lchild) q.push(curr->lchild);
            if(curr->rchild) q.push(curr->rchild);

        }
    }
    return ans;
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
    cout<<maxWidthofBt(root);

    return 0;
}