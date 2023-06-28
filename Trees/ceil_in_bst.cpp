void inorder(BinaryTreeNode<int> *root, int &res, int x)
{
    if (!root)
        return;
    if (root->data < x)
    {
        inorder(root->right, res, x);
    }
    else
    {
        res = root->data;
        inorder(root->left, res, x);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    int ans = -1;
    inorder(node, ans, x);
    return ans;
}