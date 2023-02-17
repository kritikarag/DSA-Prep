// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

void inorder(TreeNode *root, vector<int> &tree)
{
    if (!root)
        return;
    if (root->left)
        inorder(root->left, tree);
    tree.push_back(root->val);
    if (root->right)
        inorder(root->right, tree);
}
int minDiffInBST(TreeNode *root)
{
    vector<int> tree;
    inorder(root, tree);
    int result = INT_MAX;
    for (int i = 0; i < tree.size() - 1; i++)
    {
        result = min(result, tree[i + 1] - tree[i]);
    }
    return result;
}