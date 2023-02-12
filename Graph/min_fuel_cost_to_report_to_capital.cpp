// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/

long long ans = 0, s;
long long dfs(int i, int prev, vector<int> adj[], int people = 1)
{
    for (int &x : adj[i])
    {
        if (x == prev)
            continue;
        people += dfs(x, i, adj);
    }
    if (i != 0)
        ans += (people / s) + ((people % s) ? 1 : 0);
    return people;
}
long long minimumFuelCost(vector<vector<int>> &roads, int seats)
{
    int n = roads.size();
    s = seats;
    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++)
    {
        adj[roads[i][0]].push_back(roads[i][1]);
        adj[roads[i][1]].push_back(roads[i][0]);
    }
    dfs(0, 0, adj);
    return ans;
}