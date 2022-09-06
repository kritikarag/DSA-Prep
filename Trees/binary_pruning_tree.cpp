// https://leetcode.com/problems/binary-tree-pruning/

TreeNode *pruneTree(TreeNode *root)
{
    // if(!root->val && !root->left->val && !root->right->val)return NULL;
    if (root->left)
        root->left = pruneTree(root->left);
    if (root->right)
        root->right = pruneTree(root->right);
    if (!root->val && !root->left && !root->right)
        return NULL;

    return root;
}
