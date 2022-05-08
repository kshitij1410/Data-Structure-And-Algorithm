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
int preorder = 0;

struct Node *_Construct_bt_from_inorder_and_preorder(int in[], int pre[], int si, int ei)
{
    // base case
    if (si > ei)
        return NULL;

    // step1- make a root from pre
    struct Node *root = new Node(pre[preorder++]);

    // step2- serach the root in inorder for finding left and right subtree
    int inorderIdx = 0;
    for (int i = si; i < ei; i++)
    {
        if (root->key == in[i])
        {
            inorderIdx = i;
        }
    }

    // step3- make a call in left and right subtree
    root->lchild = _Construct_bt_from_inorder_and_preorder(in, pre, si, inorderIdx - 1);
    root->rchild = _Construct_bt_from_inorder_and_preorder(in, pre, inorderIdx + 1, ei);

    // step4- return root
    return root;
}

int main()
{
    int in[] = {40, 20, 50, 10, 30, 80, 70, 90};
    int pre[] = {10, 20, 40, 50, 30, 70, 80, 90};

    _Construct_bt_from_inorder_and_preorder(in, pre);
    return 0;
}