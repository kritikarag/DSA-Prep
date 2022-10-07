void dfs(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &curr, int node)
{
    curr.push_back(node);
    if (node == graph.size() - 1)
    {
        ans.push_back(curr);
    }
    else
        for (auto it : graph[node])
        {
            dfs(graph, ans, curr, it);
        }
    curr.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> ans;
    vector<int> curr;
    dfs(graph, ans, curr, 0);
    return ans;
}