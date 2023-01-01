// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/?envType=study-plan&id=data-structure-ii

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    vector<bool> vis(n, false);
    vector<int> ans;
    // vector<int>graph[n+1];
    for (int i = 0; i < edges.size(); i++)
    {
        vis[edges[i][1]] = true;
        // graph[edges[i][0]].push_back(edges[i][1]);
    } 
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            ans.push_back(i);
    }
    return ans;
}