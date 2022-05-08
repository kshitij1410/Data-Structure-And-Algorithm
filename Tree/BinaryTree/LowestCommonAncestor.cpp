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

// using lca I can also find the distance between two node
bool findPath(struct Node *root, vector<Node *> &v, int n1)
{

    // base case
    if (root == NULL)
        return false;

    v.push_back(root);

    // check n1 is equal to root->key
    if (n1 == root->data)
        return true;

    bool l = findPath(root->lchild, v, n1);
    bool r = findPath(root->rchild, v, n1);

    // if n1 is not present in the path then it will return true
    if (l || r)
        return true;

    // not present in the path then pop the last element in vector v
    v.pop_back();
    return false;
}

// this method takes 3*O(n) time and space -O(n) --not a efficient approach
struct Node *LCA(struct Node *root, int n1, int n2)
{

    if (root == NULL)
        return NULL;

    vector<Node *> v1;
    vector<Node *> v2;

    // check whether both value present in bt or not
    if (findPath(root, v1, n1) == false || findPath(root, v2, n2) == false)
        return NULL;

    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i + 1] != v2[i + 1])
            return v1[i];
    }
}

// efficient approach
// we assume both the node are present in the bt
//if any node is not present int a bt then it will give a wrong answer
struct Node* lca(struct Node *root, int n1, int n2)
{

    if (root == NULL)
        return NULL;

    if (root->data == n1 or root->data==n2)
        return root;
    
    struct Node * v1 = lca(root->lchild, n1, n2);
    struct Node * v2 = lca(root->rchild, n1, n2);

      if(v1!=NULL and v2!=NULL) return root;
      else if (v1!=NULL) return v1;
      else return v2;

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
    struct Node *temp = LCA(root, 70, 40);
    cout << temp->data << " ";
    struct Node *ans = lca(root, 70, 40);
    cout << endl<< ans->data << " ";
    return 0;
} 