// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {

        vector<int> res;
        int sz = q.size();
        while (sz--)
        {
            auto temp = q.front();
            q.pop();
            res.push_back(temp->val);
            for (auto &it : temp->children)
            {
                q.push(it);
            }
        }
        ans.push_back(res);
    }

    return ans;
}