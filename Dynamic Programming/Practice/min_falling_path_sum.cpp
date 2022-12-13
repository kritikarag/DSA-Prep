// https://leetcode.com/problems/minimum-falling-path-sum/description/

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int sum = INT_MAX;

    int rows = matrix.size(), cols = matrix[0].size();

    for (int row = 1; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            int smallest_path = matrix[row - 1][col];

            if (col > 0)
            {
                smallest_path = min(smallest_path, matrix[row - 1][col - 1]);
            }
            if (col < cols - 1)
            {
                smallest_path = min(smallest_path, matrix[row - 1][col + 1]);
            }
            matrix[row][col] += smallest_path;
        }
    }

    for (int col = 0; col != cols; ++col)
    {
        sum = min(sum, matrix[rows - 1][col]);
    }
    return sum;
}