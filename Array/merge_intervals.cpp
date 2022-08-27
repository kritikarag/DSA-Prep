vector<vector<int>> merge(vector<vector<int>> &ivt)
{
    vector<vector<int>> res;
    int n = ivt.size();

    sort(ivt.begin(), ivt.end());
    res.push_back(ivt[0]);
    for (auto x : ivt)
    {
        if (x[0] <= res.back()[1])
            res.back()[1] = max(res.back()[1], x[1]);
        else
            res.push_back(x);
    }

    return res;
}