bool isSumtree1(Node *root, stack<pair<int, bool>> &v)
{
    if (root == NULL)
    {
        v.push({0, true});
        return true;
    }
    else if (root->left == NULL and root->right == NULL)
    {
        v.push({root->data, true});
        return true;
    }
    else
    {

        bool opt1 = isSumtree1(root->left, v);
        bool opt2 = isSumtree1(root->right, v);

        bool final_opt = opt1 and opt2;
        int ans = 0;

        pair<int, bool> p;
        for (int i = 0; i < 2; i++)
        {
            p = v.top();
            v.pop();
            ans += p.first;
        }

        //   bool val=v[0].second and v[1].second;

        if (ans == root->data and final_opt)
        {
            v.push({root->data + ans, true});
            return true;
        }
        else
        {
            v.push({root->data + ans, false});
            return false;
        }
    }
}

bool isSumTree(Node *root)
{
    stack<pair<int, bool>> v;
    return isSumtree1(root, v);
}