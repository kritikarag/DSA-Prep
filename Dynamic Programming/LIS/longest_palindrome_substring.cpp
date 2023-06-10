// https://leetcode.com/problems/longest-palindromic-substring/description/
#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string s)
{
    string temp = s;
    reverse(temp.begin(), temp.end());
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int ans = 0, index = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == temp[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > ans)
                {
                    string s1 = s.substr(i - dp[i][j], dp[i][j]);
                    string s2 = s1;
                    reverse(s1.begin(), s1.end());
                    if (s1 == s2)
                    {
                        ans = dp[i][j];
                        index = i - 1;
                    }
                }
            }
            // ans = max(ans,dp[i][j]);
        }
    }
    string res = "";
    while (ans--)
    {
        res += s[index--];
    }

    return res;
}