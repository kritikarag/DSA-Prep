// https://leetcode.com/problems/group-anagrams/

TC->81ms
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (string s : strs)
    {
        string t = s;
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }

    vector<vector<string>> ans;
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}

TC->33ms

    vector<vector<string>>
    groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (string &s : strs)
    {
        string t = s;
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }

    vector<vector<string>> ans;
    ans.reserve(mp.size());
    for (auto &it : mp)
    {
        ans.emplace_back(move(it.second));
    }

    return ans;
}