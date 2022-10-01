// https://leetcode.com/problems/decode-ways/

//Bottom-Up Approach Using Recursion
int solve(string &s, int i, vector<int> &dp)
{
    if (i == s.size())
        return 1;
    if (dp[i] != 0)
        return dp[i];

    if (s[i] != '0')
        dp[i] += solve(s, i + 1, dp);
    if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
        dp[i] += solve(s, i + 2, dp);

    return dp[i];
}
int numDecodings(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    return solve(s, 0, dp);
}

// Another Top-Down Approach

int numDecodings(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '0')
            dp[i + 1] += dp[i];
        if (i - 1 >= 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')))
        {
            dp[i + 1] += dp[i - 1];
        }
    }

    return dp[n];
}

// Bottom-Up Approach Time Complexity Optimized
int numDecodings(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] != '0')
            dp[i] += dp[i + 1];
        if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
        {
            dp[i] += dp[i + 2];
        }
    }

    return dp[0];
}

// Bottom-Up Approach Space Optimized

int numDecodings(string s)
{
    int n = s.size(),prev1=1,prev2=0;
    for (int i = n - 1; i >= 0; i--)
    {
        int curr=0;
        if (s[i] != '0')
            curr += prev1;
        if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
        {
            curr+=prev2;
        }
        prev2 = prev1;
        prev1=curr;
    }

    return prev1;
}