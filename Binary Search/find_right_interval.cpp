// https://leetcode.com/problems/find-right-interval/description/

vector<int> findRightInterval(vector<vector<int>> &intvs)
{
    int n = intvs.size();
    vector<int> ans(n);
    map<int, int> mp;

    for (auto i = 0; i < n; i++)
    {
        mp[intvs[i][0]] = i;
    }
    for (int i = 0; i < intvs.size(); i++)
    {
        ans[i] = mp.lower_bound(intvs[i][1]) != end(mp) ? mp.lower_bound(intvs[i][1])->second : -1;
    }

    return ans;
}