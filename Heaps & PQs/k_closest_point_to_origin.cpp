// https://leetcode.com/problems/k-closest-points-to-origin/description/

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> res;
    for (auto it : points)
    {
        int dis = pow(it[0], 2) + pow(it[1], 2);
        pq.push({dis, {it[0], it[1]}});
    }

    int x, y;
    while (k--)
    {
        x = pq.top().second.first;
        y = pq.top().second.second;
        res.push_back({x, y});
        pq.pop();
    }
    return res;
}