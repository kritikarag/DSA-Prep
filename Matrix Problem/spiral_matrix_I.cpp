// https://leetcode.com/problems/spiral-matrix/

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int rs = 0, re = matrix.size() - 1;
    int cs = 0, ce = matrix[0].size() - 1;
    vector<int> res;
    while (rs <= re && cs <= ce)
    {
        for (int i = cs; i <= ce; i++)
        {
            res.push_back(matrix[rs][i]);
        }
        rs++;
        for (int i = rs; i <= re; i++)
        {
            res.push_back(matrix[i][ce]);
        }
        ce--;
        if (rs <= re)
        {
            for (int i = ce; i >= cs; i--)
            {
                res.push_back(matrix[re][i]);
            }
            re--;
        }
        if (cs <= ce)
        {
            for (int i = re; i >= rs; i--)
            {
                res.push_back(matrix[i][cs]);
            }
            cs++;
        }
    }
    return res;
}