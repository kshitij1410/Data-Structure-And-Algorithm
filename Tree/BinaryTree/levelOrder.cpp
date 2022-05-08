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

// level order traversal line by line
//  ans format 1 2 3 4 5
void levelOrderLineByLine(struct Node *root)
{

    queue<Node *> q;
    q.push(root);
    struct Node *curr = root;

    while (!q.empty())
    {

        curr = q.front();
        cout << curr->data << " ";

        q.pop();
        if (curr->lchild)
            q.push(curr->lchild);
        if (curr->rchild)
            q.push(curr->rchild);
    }
}

// level order traversal line by line
//  ans format 1 2
//             3 4
//             5
void levelOrderLineByLine1(struct Node *root)
{

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    struct Node *curr = root;

    while (!q.empty())
    {

        curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            cout << "\n";
            // check q is empty or not
            // for null
            if (q.empty())
            {
                break;
            }
            else
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << curr->data << " ";

            if (curr->lchild)
                q.push(curr->lchild);
            if (curr->rchild)
                q.push(curr->rchild);
        }
    }
}

// method2 without using null pointer
//  level order traversal line by line
//   ans format 1 2
//              3 4
//              5
void levelOrderLineByLine2(struct Node *root)
{

    queue<Node *> q;
    q.push(root);

    struct Node *curr = root;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->lchild)
                q.push(curr->lchild);
            if (curr->rchild)
                q.push(curr->rchild);
        }
        cout << "\n";
    }
}

int main()
{
    struct Node *root = new Node(4);
    root->lchild = new Node(2);
    root->rchild = new Node(5);
    root->lchild->lchild = new Node(1);
    root->lchild->rchild = new Node(3);
    levelOrderLineByLine(root);
    cout << "\n";
    levelOrderLineByLine1(root);
    cout << "\n";
    levelOrderLineByLine2(root);

    return 0;
}