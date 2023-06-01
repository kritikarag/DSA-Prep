// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    // your code here
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            res = max(res, dp[i][j]);
        }
    }
    return res;
}