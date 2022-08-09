void leftleaf(TreeNode *root, int &sum)
{
    if (root == NULL)
        return;

    if (root->left && root->left->left == NULL && root->left->right == NULL)
        sum += root->left->val;
    leftleaf(root->left, sum);
    leftleaf(root->right, sum);
}

int sumOfLeftLeaves(TreeNode *root)
{
    int sum = 0;
    leftleaf(root, sum);
    return sum;
}