// https://leetcode.com/problems/maximal-square/
#include<bits/stdc+.h>
using namespace std;
int maximalSquare(vector<vector<char>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> mat(n, vector<int>(m));
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mat[i][j] = matrix[i][j] - '0';
            res = max(res, mat[i][j]);
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (mat[i][j])
            {
                mat[i][j] += min(mat[i - 1][j], min(mat[i - 1][j - 1], mat[i][j - 1]));
            }
            res = max(mat[i][j], res);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return res * res;
}