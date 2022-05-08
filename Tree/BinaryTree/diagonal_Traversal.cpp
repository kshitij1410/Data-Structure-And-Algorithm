//Order not matter according to level wise traversal
vector diagonal(Node *root)
{

    vector<int> v;

    // base case
    if (root == NULL)
        return v;

    queue<Node *> q;

    q.push(root);
    Node *temp = root;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        while (temp != NULL)
        {
            v.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            temp = temp->right;
        }
    }
    return v;
}