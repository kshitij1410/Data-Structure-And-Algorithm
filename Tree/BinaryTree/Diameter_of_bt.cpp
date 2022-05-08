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

// struct Diameter{
//     int hei,int dia;
//     Diameter(int hei,int dia){
//         this->hei=hei;
//         this->dia=dia;
//     }
// };

// pair<int,int>pr;

// method 1 O(n*n)
// diameter and height function both take O(n)time

// method 2 -O(n) + O(n)space for prestoring the height in the hashmap or unordered_map

// efficient solution
// method 3- O(n) time complexity with O(1) space complexity

// int res we store diameter of tree
int res = 0;

int height(struct Node *root)
{

    // base case
    if (root == NULL)
        return 0;

    int hl = height(root->lchild);
    int hr = height(root->rchild);
    res = max(res, hl + hr + 1); // store diameter
    
    return max(hl, hr) + 1;      // return height
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
    height(root);
    cout<<res;
    return 0;
}