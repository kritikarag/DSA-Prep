// https://leetcode.com/problems/last-day-where-you-can-still-cross/description/

int latestDayToCross(int row, int col, vector<vector<int>> &cells)
{
    int low = 1, high = cells.size(), ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (solve(row, col, mid, cells))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

bool solve(int row, int col, int mid, vector<vector<int>> &cells)
{
    vector<vector<bool>> grid(row, vector<bool>(col, 0));

    for (int i = 0; i < mid; i++)
    {
        grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < col; i++)
    {
        if (grid[0][i] == 0)
        {
            q.push({0, i});
            grid[0][i] = 1;
        }
    }

    int dir[5] = {0, -1, 0, 1, 0};

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        if (r == row - 1)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int tempr = r + dir[i], tempc = c + dir[i + 1];

            if (tempr < 0 || tempr >= row || tempc < 0 || tempc >= col || grid[tempr][tempc] == 1)
                continue;

            grid[tempr][tempc] = 1;
            q.push({tempr, tempc});
        }
    }

    return false;
}