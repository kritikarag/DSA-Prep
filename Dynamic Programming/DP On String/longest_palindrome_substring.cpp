// https://leetcode.com/problems/longest-palindromic-substring/

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