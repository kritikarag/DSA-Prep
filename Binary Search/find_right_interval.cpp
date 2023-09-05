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

vector<string> ans;
unordered_map<string, pair<string, string>> mp;
unordered_map<string, int> tt;
unordered_map<string, int> spent;
for (auto it : queries)
{
    if (it.size() == 4)
    {
        if (mp.find(it[1]) != mp.end())
        {
            ans.push_back("false");
        }
        else
        {
            mp[it[1]] = {it[2], it[3]};
            ans.push_back("true");
            spent[it[1]] = 0;
        }
    }
    else if (it.size() == 3)
    {
        if (mp.find(it[1]) == mp.end())
        {
            ans.push_back("invalid_request");
        }
        else
        {
            if (tt.find(it[1]) == tt.end())
            {
                tt[it[1]] = stoi(it[2]);
            }
            else
            {
                int curr = stoi(it[2]) - tt[it[1]];
                spent[it[1]] = spent[it[1]] + curr;
                tt.erase(it[1]);
            }
            ans.push_back("registered");
        }
    }
    else
    {
        if (mp.find(it[1]) == mp.end())
        {
            ans.push_back("");
        }
        else
        {
            ans.push_back(to_string(spent[it[1]]));
        }
    }
}

return ans;