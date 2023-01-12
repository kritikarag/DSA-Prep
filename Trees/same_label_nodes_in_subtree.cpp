// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/

void dfs(int node, int prev, vector<int> graph[], vector<int> &res, vector<int> &freq, string &labels)
{
    int prevcount = freq[labels[node] - 'a'];
    freq[labels[node] - 'a']++;

    for (int currnode : graph[node])
    {
        if (prev == currnode)
            continue;
        dfs(currnode, node, graph, res, freq, labels);
    }

    res[node] += freq[labels[node] - 'a'] - prevcount;
}
vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{
    vector<int> graph[n];
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> res(n, 0), freq(26, 0);
    dfs(0, 0, graph, res, freq, labels);

    return res;
}