// https://leetcode.com/problems/deepest-leaves-sum/description/

int deepestLeavesSum(TreeNode *root)
{
    int ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        // Resetting sum bcz at this point we know that there exist a deeper level that we need to explore
        ans = 0;
        while (n--)
        {
            auto temp = q.front();
            q.pop();
            ans += temp->val;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}