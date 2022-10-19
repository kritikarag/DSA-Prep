// https://leetcode.com/problems/binary-tree-paths/

void solve(TreeNode *root, vector<string> &res, string curr)
{
    if (!root)
        return;
    if (root->left || root->right)
        curr += to_string(root->val) + "->";
    else
    {
        curr += to_string(root->val);
        res.push_back(curr);
    }
    solve(root->left, res, curr);
    solve(root->right, res, curr);
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> res;
    string curr = "";
    solve(root, res, curr);
    return res;
}