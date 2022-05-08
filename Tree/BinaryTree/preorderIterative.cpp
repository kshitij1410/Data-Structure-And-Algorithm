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

// METHOD1
// O(N) TIME AND SPACE 0(N)
vector<int> preorderIterative(Node *root)
{
    vector<int> v;
    stack<Node *> s;
    if (root == NULL)
        return v;
    Node *temp = root;

    s.push(root);

    while (!s.empty())
    {

        temp = s.top();
        s.pop();
        v.push_back(temp->data);

        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }

    return v;
}

// METHOD 2-
// O(N) AND O(H) SPACE COMPLEXITY

// method 1: Time-O(N) and space O(n)
// maintain a stack and push right child and then left child

// method 2: Time O(n) and space O(H)
//  maintain a stack and push only right child rather than left child
vector<int> preOrder(Node *root)
{
    vector<int> ans;
    stack<Node *> st;

    if (root == NULL)
        return ans;

    Node *curr = root;

    while (curr != NULL or !st.empty())
    {
        if (curr != NULL)
        {
            while (curr)
            {
                ans.push_back(curr->data);

                if (curr->right)
                    st.push(curr->right);

                curr = curr->left;
            }
        }
        else
        {
            curr = st.top();
            st.pop();
        }
    }

    return ans;
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
    preorderIterative(root);
    return 0;
}