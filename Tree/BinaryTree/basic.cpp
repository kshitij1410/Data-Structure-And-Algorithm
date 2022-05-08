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

// In order -- recursive approach
void printInOrder(struct Node *root)
{

    if (root == NULL)
        return;

    printInOrder(root->lchild);
    cout << root->data << " ";
    printInOrder(root->rchild);
}

// In order -iterative approach

vector<int> inOrder(Node *root)
{
    vector<int> v;
    stack<Node *> st;
    if (root == NULL)
        return v;

    Node *curr = root;


    while (curr != NULL or !st.empty())
    {
        if (curr != NULL)
        {
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
        }
        else
        {
            curr = st.top();
            st.pop();
            v.push_back(curr->data);
            curr = curr->right;
        }
    }

    return v;
}

// calcualte height of tree
int getHeight(struct Node *root)
{

    if (root == NULL)
        return -1;
    int h1 = getHeight(root->lchild);
    int h2 = getHeight(root->rchild);

    if (h1 > h2)
        return h1 + 1;
    else
        return h2 + 1;
}

// size of binary tree ie. count all nodes in bt

int sizeInBt(struct Node *root)
{
    if (root == NULL)
        return 0;

    int h1 = sizeInBt(root->lchild);
    int h2 = sizeInBt(root->rchild);

    return h1 + 1 + h2;
}

// find out maximum value in it
int maxValue(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    return max(root->data, max(maxValue(root->lchild), maxValue(root->rchild)));
}

int main()
{
    struct Node *root = new Node(4);
    root->lchild = new Node(2);
    root->rchild = new Node(5);
    root->lchild->lchild = new Node(1);
    root->lchild->rchild = new Node(3);

    // In order traversal
    if (root != NULL)
        printInOrder(root);
    cout << endl;
    printInOrderIter(root);

    cout << endl;

    // calcuate height of bt
    int ans = getHeight(root);
    cout << ans;

    // calcualte total node in bt
    if (root != NULL)
    {
        int size = sizeInBt(root);
        cout << " " << size << " ";
    }

    // max value in bt
    int mxNodeValue = maxValue(root);
    cout << mxNodeValue << " ";

    return 0;
}