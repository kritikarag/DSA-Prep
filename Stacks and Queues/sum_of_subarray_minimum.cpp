// https://leetcode.com/problems/sum-of-subarray-minimums/

#include<bits/stdc++.h>
using namespace std;
int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n);
    stack<int> st;

    int ans = 0, mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if (!st.empty())
        {
            int j = st.top();
            dp[i] = dp[j] + arr[i] * (i - j);
        }
        else
        {
            dp[i] = arr[i] * (i + 1);
        }
        ans = (ans + dp[i]) % mod;
        st.push(i);
    }
    return ans;
}