//1st Approach

bool searchMatrix(vector<vector<int>> &mt, int target){
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

//2nd Approach

bool binarysearch(vector<int> &mt, int target)
{
    int low = 0, high = mt.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mt[mid] == target)
            return true;
        else if (mt[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int lrow = 0, hrow = n - 1;
    while (lrow <= hrow)
    {
        int mid = lrow + (hrow - lrow) / 2;
        if (matrix[mid][0] <= target && matrix[mid][m - 1] >= target)
        {
            return binarysearch(matrix[mid], target);
        }
        else if (matrix[mid][0] > target)
            hrow = mid - 1;
        else
            lrow = mid + 1;
    }

    return false;
}