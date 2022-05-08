#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int data;
    bool x;
    struct Node *lchild, *rchild;

    Node(int data)
    {
        this->data = data;
        lchild = rchild = NULL;
        x = false;
    }
};

int height(struct Node *root)
{

    // base case
    if (root == NULL)
        return 0;

    int hl = height(root->lchild);
    int hr = height(root->rchild);
    if (root->x == true)
        return max(hl, hr);

    return max(hl, hr) + 1; // return height
}

int LongestCheat(struct Node *root)
{
    if (root == NULL)
        return 0;
    return height(root);
}

void buildTree(vector<pair<int, int>> v, vector<int> input4)
{
    int flag = 0;
    for (int i = 0; i < v.size(); i++)
    {
        flag = 0;
        int a = v[i].first;
        int b = v[i].second;
        for (int j = 0; j < input4.size(); j++)
        {
            if (b == input4[i])
            {
                flag = 1;
                break;
            }
        }

        struct Node *node 1 = new Node(a);
        struct Node *node 2 = new Node(b);
        if (node1->lchild != NULL)
        {
            node1->rchild = node2;
            if (flag == 1)
                node2->x = true;
        };
        else
        {
            node1->lchild = node2;
            if (flag == 1)
                node2->x = true;
        }
    }
}

int main()
{
    struct Node *root = new Node(1);
    int input1;
    cin >> input;
    vector<pair<int, int>> v;
    for (int i = 0; i < input - 1; i++)
    {
        int c, d : cin >> c >> d;
        v.push_back({c, d});
    }

    int input3;
    cin >> input3;
    vector<int> input4;
    for (int i = 0; i < input3; i++)
    {
        int t;
        cin >> t;
        input4.push_back(t);
    }
    for (int j = 0; j < input4.size(); j++)
    {
        if (input4[j] == 1)
        {
            root->x = true;
        }
    }
    buildTree(v, input4);
    cout << LongestCheat(root);

    return 0;
}