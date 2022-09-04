// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        TreeNode *curr = temp.first;
        int col = temp.second.first, level = temp.second.second;
        mp[col][level].insert(curr->val);
        if (curr->left)
        {
            q.push({curr->left, {col - 1, level + 1}});
        }
        if (curr->right)
        {
            q.push({curr->right, {col + 1, level + 1}});
        }
    }

    vector<vector<int>> res;
    for (auto it : mp)
    {
        vector<int> temp;
        for (auto p : it.second)
        {
            temp.insert(temp.end(), p.second.begin(), p.second.end());
        }

        temp.push_back(temp);
    }

    return res;
}