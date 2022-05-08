#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void visitLeftNode(Node *root, vector<int> &ans)
{
    if (root == NULL || root->left == NULL and root->right == NULL)
        return;

    if (root->left == NULL and root->right != NULL)
    {
        ans.push_back(root->data);
        visitLeftNode(root->right, ans);
    }
    if (root->left != NULL)
    {
        ans.push_back(root->data);
        visitLeftNode(root->left, ans);
    }
}

void addrightBoundry(Node *root, vector<int> &ans)
{
    if (root == NULL || root->left == NULL and root->right == NULL)
        return;

    if (root->right == NULL and root->left != NULL)
    {

        addrightBoundry(root->left, ans);
        ans.push_back(root->data);
    }
    if (root->right != NULL)
    {

        addrightBoundry(root->right, ans);
        ans.push_back(root->data);
    }
}

void addLeaves(Node *root, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        res.push_back(root->data);
    }
    addLeaves(root->left, res);
    addLeaves(root->right, res);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;

    // base case
    if (root == NULL)
        return ans;
    if (root->left == NULL and root->right == NULL)
    {
        ans.push_back(root->data);
        return ans;
    }

    ans.push_back(root->data);

    visitLeftNode(root->left, ans);

    addLeaves(root, ans);

    addrightBoundry(root->right, ans);

    return ans;
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    // root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(506);
    root->left->right->right = new Node(520);
    root->left->right->right->right = new Node(150);
    root->right->right = new Node(70);

    vector<int> ans = boundary(root);
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}