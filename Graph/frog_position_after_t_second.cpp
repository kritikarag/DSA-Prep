// https://leetcode.com/problems/frog-position-after-t-seconds/

#include<bits/stdc++.h>
using namespace std;
vector<double> prob;
vector<bool> vis;
void solve(vector<int> graph[], int node, int timeleft)
{
    if (timeleft < 0)
        return;
    vis[node] = true;

    // prob[node] = 0.0;
    int count = 0;
    double child_prob;
    for (int child : graph[node])
    {
        if (!vis[child])
            count++;
    }
    if (count)
    {
        child_prob = double(prob[node] / (count * 1.0));
        prob[node] = 0.0;

        for (int child : graph[node])
        {
            if (!vis[child])
            {
                prob[child] = child_prob;
                solve(graph, child, timeleft - 1);
            }
        }
    }
}
double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
{
    prob.resize(n + 1, 0.0);
    vis.resize(n + 1, false);

    vector<int> graph[n + 1];
    for (auto &it : edges)
    {
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    prob[1] = 1.0;
    solve(graph, 1, t - 1);
    return prob[target];
}