vector<vector<int>> intervalIntersection(vector<vector<int>> &f, vector<vector<int>> &s)
{
    vector<vector<int>> res;
    int i = 0, j = 0;
    while (i < f.size() && j < s.size())
    {
        if ((f[i][0] >= s[j][0] && f[i][0] <= s[j][1]) || (s[j][0] >= f[i][0] && s[j][0] <= f[i][1]))
        {
            res.push_back({max(f[i][0], s[j][0]), min(f[i][1], s[j][1])});
        }
        if (f[i][1] < s[j][1])
            i++;
        else
            j++;
    }

    return res;
}