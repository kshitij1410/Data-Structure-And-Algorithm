//important 

vector<int> postOrder(Node *root)
{
    vector<int> postorder;
    if (root == NULL)
        return postorder;

    stack<Node *> st1;

    Node *current = root;

    while (current != NULL || !st1.empty())
    {
        if (current != NULL)
        {
            st1.push(current);
            current = current->left;
        }

        else
        {
            Node *temp = st1.top()->right;
            if (temp == NULL)
            {
                temp = st1.top();
                st1.pop();
                postorder.push_back(temp->data);
                while (!st1.empty() && temp == st1.top()->right)
                {
                    temp = st1.top();
                    st1.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                current = temp;
            }
        }
    }

    return postorder;
}