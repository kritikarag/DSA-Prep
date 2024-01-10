// https://leetcode.com/problems/longest-palindromic-substring/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int res = 0;
int index = 0;
int solve(int i, int j, string &s, string &r)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == r[j])
    {
        dp[i][j] = 1 + solve(i - 1, j - 1, s, r);
    }
    else
    {
        dp[i][j] = 0;
    }

    solve(i - 1, j, s, r);
    solve(i, j - 1, s, r);

    return dp[i][j];
}
string longestPalindrome(string s)
{
    int n = s.length();
    string r = s;
    reverse(r.begin(), r.end());

    dp.resize(n, vector<int>(n, -1));

    solve(n - 1, n - 1, s, r);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] > res)
            {
                // cout<<i<<" "<<dp[i][j]<<endl;
                string temp1 = s.substr(i - dp[i][j] + 1, dp[i][j]);
                string temp2 = temp1;
                reverse(temp2.begin(), temp2.end());

                if (temp1 == temp2)
                {
                    index = i;
                    res = dp[i][j];
                }
            }
        }
    }
    string ans = "";
    while (res--)
    {
        ans += s[index--];
    }
    return ans;
}

string longestPalindrome(string s1)
{
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int n = s1.length(), index;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int ans = 0;
    // string res="";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (ans < dp[i][j])
                {
                    string temp = s1.substr(i - dp[i][j], dp[i][j]);
                    string rev = temp;
                    reverse(rev.begin(), rev.end());
                    if (temp == rev)
                    {
                        ans = max(dp[i][j], ans);
                        index = i - 1;
                    }
                }
            }
        }
    }

    string res = "";
    while (ans--)
    {
        res += s1[index--];
    }

    return res;
}

string longestPalindrome(string s)
{
    int n = s.length();
    int pos = 0;
    int len = 1;
    for (int i = 0; i < n;)
    {
        int left = i, right = i;
        while (right < n && s[right] == s[right + 1])
            right++;
        i = right + 1;
        while (right < n && left > 0 && s[right + 1] == s[left - 1])
        {
            right++;
            left--;
        }
        int curr_len = right - left + 1;
        if (curr_len > len)
        {
            len = curr_len;
            pos = left;
        }
    }
    return s.substr(pos, len);
}