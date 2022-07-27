bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = mt.size(), m = mt[0].size();
    int low = 0, high = m * n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;

        if (mt[row][col] == target)
            return true;

        else if (mt[row][col] >= target)
            high = mid - 1;

        else
            low = mid + 1;
    }
    return false;
}