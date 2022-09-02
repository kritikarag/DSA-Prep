// https://leetcode.com/problems/average-of-levels-in-binary-tree/

//APPROACH 1 (USING BFS)

vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> res;
    queue<TreeNode *> q;
    q.push(root);
    long long level = 1;
    while (!q.empty())
    {
        long long sum = 0, n = q.size(), count = 0;
        while (n--)
        {
            count++;
            sum += q.front()->val;
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        res.push_back(double(sum) / count);
    }

    return res;
}
