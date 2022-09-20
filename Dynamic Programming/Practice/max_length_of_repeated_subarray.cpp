// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

//1ST APPROACH
int findLength(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxi = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxi = max(dp[i][j], maxi);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return maxi;
}

//2ND APPROACH

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();

    vector<int> prev(n + 1, 0);
    int maxi = 0;

    for (int i = 1; i <= n; i++)
    {
        vector<int> curr(m + 1, 0);
        for (int j = 1; j <= m; j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                curr[j] = prev[j - 1] + 1;
                maxi = max(curr[j], maxi);
            }
            else
            {
                curr[j] = 0;
            }
        }
        prev = curr;
    }

    return maxi;
}