// https://leetcode.com/problems/cheapest-flights-within-k-stops/

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];

    for (auto flight : flights)
    {
        adj[flight[0]].push_back({flight[1], flight[2]});
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dis(n, INT_MAX);

    while (!q.empty())
    {
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        if (stops > k)
            continue;

        for (auto it : adj[node])
        {
            int temp = it.first;
            int curr = it.second;

            if (dis[temp] > cost + curr && stops <= k)
            {
                dis[temp] = cost + curr;
                q.push({stops + 1, {temp, dis[temp]}});
            }
        }
    }

    if (dis[dst] == INT_MAX)
        return -1;
    else
        return dis[dst];
}