// https://leetcode.com/problems/path-with-minimum-effort/
TC : ElogV
    n *m *4 * log(n *m) 
int minimumEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    int dir[5] = {0, 1, 0, -1, 0};
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

    dis[0][0] = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {0, 0}});

    while (!pq.empty())
    {
        int diff = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;

        if (row == n - 1 && col == m - 1)
            return dis[row][col];
        pq.pop();

        for (int i = 0; i < 4; i++)
        {
            int cr = row + dir[i];
            int cc = col + dir[i + 1];
            if (cr >= 0 && cc >= 0 && cr < n && cc < m)
            {
                int curr_diff = max(abs(heights[row][col] - heights[cr][cc]), diff);
                if (curr_diff < dis[cr][cc])
                {
                    dis[cr][cc] = curr_diff;
                    pq.push({dis[cr][cc], {cr, cc}});
                }
            }
        }
    }
    return 0;
}