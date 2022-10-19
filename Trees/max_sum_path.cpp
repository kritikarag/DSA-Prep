// https://leetcode.com/problems/binary-tree-maximum-path-sum/

int solve(TreeNode *root, int &ans)
{
    if (root == NULL)
        return 0;

    int leftsum = max(solve(root->left, ans), 0);
    int rightsum = max(solve(root->right, ans), 0);

    ans = max(ans, leftsum + rightsum + root->val);

    return root->val + max(rightsum, leftsum);
}
int maxPathSum(TreeNode *root)
{
    int ans = INT_MIN;
    solve(root, ans);
    return ans;
}