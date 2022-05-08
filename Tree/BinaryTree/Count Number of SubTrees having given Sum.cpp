
int cnt, target;

int findSum(Node* root)
{
    if(!root)
    return 0;
    
    int Sum = root->data + findSum(root->left) + findSum(root->right);
    
    if(Sum == target)
    cnt++;
    
    return Sum;
}
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	cnt = 0;
	target = X;
	
	findSum(root);
	
	return cnt;
}
