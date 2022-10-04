// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

int countNegatives(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    if (grid[m - 1][n - 1] >= 0)
        return 0;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (grid[i][mid] < 0)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        ans += n - low;
    }
    return ans;
}