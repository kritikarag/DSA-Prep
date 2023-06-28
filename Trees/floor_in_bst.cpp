//

//APPROACH - 1

void inorder(TreeNode<int> *root, vector<int> &res)
{
    if (!root)
        return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}
int floorInBST(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> res;
    inorder(root, res);
    int ans = -1;
    for (int i : res)
    {
        if (i > x)
            break;
        ans = i;
    }
    return ans;
}

// APPROACH - 2

void inorder(TreeNode<int> *root, int &res, int x)
{
    if (!root)
        return;
    if (root->val > x)
    {
        inorder(root->left, res, x);
    }
    else
    {
        res = root->val;
        inorder(root->right, res, x);
    }
}
int floorInBST(TreeNode<int> *root, int x)
{
    // Write your code here.

    int ans = -1;
    inorder(root, ans, x);
    return ans;
}