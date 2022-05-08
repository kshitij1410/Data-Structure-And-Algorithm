
unordered_map<Node *, int> dp;
int helper(Node *root)
{
    if (root == NULL)
        return 0;

    if (dp[root])
        return dp[root];

    int inc = root->data;

    // case 1
    if (root->left)
    {
        inc += helper(root->left->left);
        inc += helper(root->left->right);
    }
    // case 2
    if (root->right)
    {
        inc += helper(root->right->left);
        inc += helper(root->right->right);
    }

    int exc = helper(root->left) + helper(root->right);

    return dp[root] = max(exc, inc);
}

// Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root)
{
    return helper(root);
    
}