// https://leetcode.com/problems/find-eventual-safe-states/description/?envType=study-plan-v2&id=graph-theory

#include<bits/stdc++.h>
using namespace std;
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> nodes[n], outdegree(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        for (int j : graph[i])
        {
            nodes[j].push_back(i);
        }
        outdegree[i] = graph[i].size();
        if (outdegree[i] == 0)
            q.push(i);
    }
    vector<int> ans, safe(n, 0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        safe[u] = 1;
        for (int v : nodes[u])
        {
            if (--outdegree[v] == 0)
                q.push(v);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (outdegree[i] == 0)
            ans.push_back(i);
    }

    return ans;
}