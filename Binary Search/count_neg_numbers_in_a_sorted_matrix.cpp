// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/?envType=study-plan-v2&envId=binary-search

int countNegatives(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    if (grid[m - 1][n - 1] >= 0)
        return 0;
    if (grid[0][0] < 0)
        return n * m;
    int ans = 0;

    int low = 0, high = m - 1;

    while (low < n && high >= 0)
    {
        if (grid[low][high] < 0)
        {
            ans += n - low;
            high--;
        }
        else
            low++;
    }
    return ans;
}