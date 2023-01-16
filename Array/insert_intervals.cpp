// https://leetcode.com/problems/insert-interval/description/

vector<vector<int>> insert(vector<vector<int>> &intv, vector<int> &newintv)
{
    vector<vector<int>> ans;
    int i = 0, n = intv.size();

    while (i < n && intv[i][0] < newintv[0])
    {
        ans.push_back(intv[i]);
        i++;
    }

    if (ans.size() == 0 || newintv[0] > ans.back()[1])
        ans.push_back(newintv);
    else
        ans.back()[1] = max(newintv[1], ans.back()[1]); 

    while (i < n)
    {
        if (intv[i][0] <= ans.back()[1])
            ans.back()[1] = max(intv[i][1], ans.back()[1]);
        else
            ans.push_back(intv[i]);
        i++;
    }

    return ans;
}