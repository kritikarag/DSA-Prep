// https://leetcode.com/problems/binary-tree-right-side-view/description/

// Approach - 1
vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return {};
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        int n = q.size();
        while (n--)
        {
            auto node = q.front();
            q.pop();
            if (node->right)
                q.push(node->right);
            if (node->left)
                q.push(node->left);
        }
    }
    return ans;
}


// Approach - 2
void solve(TreeNode *node, int level, vector<int> &ans)
{
    if (!node)
        return;
    if (ans.size() == level)
        ans.push_back(node->val);

    solve(node->right, level + 1, ans);
    solve(node->left, level + 1, ans);
}
vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}