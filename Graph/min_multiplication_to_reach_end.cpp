// https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    // code here
    queue<pair<int, int>> q;
    q.push({start, 0});
    vector<int> dis(100000, INT_MAX);
    dis[start] = 0;
    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;

        q.pop();

        if (end == node)
            return steps;

        for (auto it : arr)
        {
            int nums = (it * node) % 100000;
            if (steps + 1 < dis[nums])
            {
                dis[nums] = steps + 1;
                q.push({nums, dis[nums]});
            }
        }
    }
    return -1;
}

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    // code here

    if (start == end)
        return 0;
    int mod = 100000;

    queue<pair<int, int>> q;

    vector<bool> vis(mod, false);
    q.push({start, 0});
    vis[start] = true;

    while (!q.empty())
    {
        int product = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (int i = 0; i < arr.size(); i++)
        {
            int curr = (product * arr[i]) % mod;
            if (curr == end)
                return steps + 1;

            if (!vis[curr])
            {
                vis[curr] = true;
                q.push({curr, steps + 1});
            }
        }
    }

    return -1;
}