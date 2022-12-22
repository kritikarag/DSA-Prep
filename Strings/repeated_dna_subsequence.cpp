// https://leetcode.com/problems/repeated-dna-sequences/description/

vector<string> findRepeatedDnaSequences(string s)
{
    int n = s.length();
    if (n <= 10)
        return {};
    // if(n==10)return {s};
    int i = 0, j = 10;
    map<string, int> mp;
    while (i < n && j < n)
    {
        string s1 = s.substr(i, 10);
        mp[s1]++;
        i++;
    }
    vector<string> ans;
    for (auto it : mp)
    {
        if (it.second > 1)
            ans.push_back(it.first);
    }
    return ans;
}