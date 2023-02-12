// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/

/*We need to track the number of people that reach each node and divide that by the number of seats per car, 
this will tell us the number of cars required to take us to the node that is closer to node0*/
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