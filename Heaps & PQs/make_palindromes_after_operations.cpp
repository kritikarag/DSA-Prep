// https://leetcode.com/problems/maximum-palindromes-after-operations/description/

#include<bits/stdc++.h>
using namespace std;
int maxPalindromesAfterOperations(vector<string> &words)
{
    int n = words.size(), answer = 0;
    sort(words.begin(), words.end(), [](string &s1, string &s2)
         { return s1.size() < s2.size(); });
    unordered_map<char, int> mp;
    for (string &s : words)
    {
        for (char c : s)
            mp[c]++;
    }
    priority_queue<pair<int, char>> even, odd;

    for (auto &it : mp)
    {
        if (it.second & 1)
        {
            even.push({it.second - 1, it.first});
            odd.push({1, it.first});
        }
        else
        {
            even.push({it.second, it.first});
        }
    }

    for (string s : words)
    {
        int req = s.length();
        if (req & 1)
        {
            if (!odd.empty())
            {
                req--;
                odd.pop();
            }
        }
        while (req && !even.empty())
        {
            int curr = even.top().first;
            if (curr > req)
            {
                auto temp = even.top();
                even.pop();
                temp.first -= req;
                even.push(temp);
                req = 0;
            }
            else
            {
                req -= even.top().first;
                even.pop();
            }
        }
        if (req == 0)
            answer++;
    }
    return answer;
}
