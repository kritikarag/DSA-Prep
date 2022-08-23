// APPROACH 1
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
        return root;
    else if ((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val))
        return root;

    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    else
        return lowestCommonAncestor(root->right, p, q);
}

// APPROACH 2

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    return root;
}