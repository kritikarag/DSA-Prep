// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

vector<int> largestValues(TreeNode *root)
{
    if (!root)
        return {};
    queue<TreeNode *> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        int n = q.size();
        int curr = INT_MIN;
        while (n--)
        {
            auto temp = q.front();
            q.pop();
            curr = max(curr, temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        ans.push_back(curr);
    }

    return ans;
}