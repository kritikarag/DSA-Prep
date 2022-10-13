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