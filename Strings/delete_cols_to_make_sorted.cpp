// https://leetcode.com/problems/delete-columns-to-make-sorted/description/

int minDeletionSize(vector<string> &strs)
{
    int res = 0;
    int n = strs.size(), m = strs[0].size();
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (strs[i][j] > strs[i + 1][j])
            {
                res++;
                break;
            }
        }
    }
    return res;
}