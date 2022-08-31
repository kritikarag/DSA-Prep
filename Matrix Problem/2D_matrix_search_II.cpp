// https://leetcode.com/problems/search-a-2d-matrix-ii/

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {
        int val = matrix[row][col];

        if (val == target)
            return true;
        else if (val < target)
            row++;
        else
            col--;
    }

    return false;
}