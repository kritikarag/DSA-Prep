// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || root == p || root == q)
        return root;

    TreeNode *leftnode = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightnode = lowestCommonAncestor(root->right, p, q);

    if (!leftnode)
        return rightnode;
    else if (!rightnode)
        return leftnode;
    return root;
}