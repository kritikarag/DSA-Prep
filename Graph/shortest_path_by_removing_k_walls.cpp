// https://practice.geeksforgeeks.org/problems/shortest-path-by-removing-k-walls/1

int shotestPath(vector<vector<int>> mat, int n, int m, int k)
{
    // code here
    vector<vector<int>> vis(n, vector<int>(m, -1));
    queue<vector<int>> q;
    q.push({0, 0, 0, k}); // x, y, currentLength, remaining k

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = cur[0];
        int y = cur[1];

        if (x < 0 || y < 0 || x >= n || y >= m)
            continue; // edge case
        if (x == n - 1 && y == m - 1)
            return cur[2];  // reached to destination
        if (mat[x][y] == 1) // checking for obstacles
            if (cur[3] > 0)
                cur[3]--;
            else
                continue;
        if (vis[x][y] != -1 && vis[x][y] >= cur[3])
            continue; // important case
        vis[x][y] = cur[3];

        q.push({x + 1, y, cur[2] + 1, cur[3]});
        q.push({x - 1, y, cur[2] + 1, cur[3]});
        q.push({x, y + 1, cur[2] + 1, cur[3]});
        q.push({x, y - 1, cur[2] + 1, cur[3]});
    }
    return -1;
}