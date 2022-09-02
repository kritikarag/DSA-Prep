// https://leetcode.com/problems/spiral-matrix-ii/

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int rs = 0, cs = 0, re = n - 1, ce = n - 1;
    int count = 1;

    while (rs <= re && cs <= ce)
    {
        for (int i = cs; i <= ce; i++)
        {
            matrix[rs][i] = count++;
        }
        rs++;
        for (int i = rs; i <= re; i++)
        {
            matrix[i][ce] = count++;
        }
        ce--;
        if (rs <= re)
        {
            for (int i = ce; i >= cs; i--)
            {
                matrix[re][i] = count++;
            }
            re--;
        }
        if (cs <= ce)
        {
            for (int i = re; i >= rs; i--)
            {
                matrix[i][cs] = count++;
            }
            cs++;
        }
    }
    return matrix;
}