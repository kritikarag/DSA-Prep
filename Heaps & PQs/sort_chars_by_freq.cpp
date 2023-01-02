// https://leetcode.com/problems/sort-characters-by-frequency/description/

string frequencySort(string s)
{
    unordered_map<char, int> mp;
    for (char c : s)
        mp[c]++;
    priority_queue<pair<int, char>> pq;
    for (auto it : mp)
    {
        pq.push({it.second, it.first});
    }
    string ans = "";
    while (!pq.empty())
    {
        char temp = pq.top().second;
        int n = pq.top().first;
        pq.pop();
        ans.append(n, temp);
    }
    return ans;
}
