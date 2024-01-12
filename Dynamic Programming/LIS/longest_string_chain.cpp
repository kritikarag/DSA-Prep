// https://leetcode.com/problems/longest-string-chain/description/

#include<bits/stdc++.h>
using namespace std;

static bool compare(string &s1, string &s2)
{
    return s1.size() < s2.size();
}
static bool canBeEqual(string &s1, string &s2)
{

    int l1 = s1.size();
    int l2 = s2.size();

    if (l1 + 1 != l2)
        return false;

    int first = 0;
    int second = 0;
    while (second < l2)
    {
        if (first < s1.size() && s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
        {
            second++;
        }
    }
    if (first + 1 == second)
        return true;
    else
        return false;
}

// Memoization
vector<vector<int>> dp;
int solve(int prev, int curr, vector<string> &words)
{
    if (curr >= words.size())
        return 0;

    if (dp[prev + 1][curr] != -1)
        return dp[prev + 1][curr];

    int take = 0;
    if (prev == -1 || canBeEqual(words[prev], words[curr]))
    {
        take = 1 + solve(curr, curr + 1, words);
    }

    int not_take = solve(prev, curr + 1, words);

    return dp[prev + 1][curr] = max(take, not_take);
}
int longestStrChain(vector<string> &words)
{
    sort(words.begin(), words.end(), compare);
    int n = words.size();
    dp.resize(n, vector<int>(n, -1));

    return solve(-1, 0, words);
}

// Tabulation
int longestStrChain(vector<string> &words)
{
    sort(words.begin(), words.end(), compare);
    int n = words.size();
    vector<int> dp(n, 1);
    int maxChain = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (canBeEqual(words[j], words[i]) && dp[i] < 1 + dp[j])
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxChain)
        {
            maxChain = dp[i];
        }
    }

    return maxChain;
}