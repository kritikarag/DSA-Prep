// https://leetcode.com/problems/sum-of-subarray-ranges/description/

#include<bits/stdc++.h>
using namespace std;

long long subArrayRanges(vector<int> &nums)
{
    int n = nums.size(), mod = 1e9 + 7;
    vector<long long> maxi(n, 0), mini(n, 0);
    stack<long long> st;
    for (long long i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
            st.pop();
        if (!st.empty())
        {
            int j = st.top();
            mini[i] = mini[j] + nums[i] * (i - j);
        }
        else
        {
            mini[i] = nums[i] * (i + 1);
        }
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (long long i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
            st.pop();
        if (!st.empty())
        {
            long long j = st.top();
            maxi[i] = maxi[j] + nums[i] * (i - j);
        }
        else
        {
            maxi[i] = nums[i] * (i + 1);
        }
        st.push(i);
    }
    // for(int i:mini)cout<<i<<" ";
    // cout<<endl;
    // for(int i:maxi)cout<<i<<" ";
    // cout<<endl;
    long long result = 0;
    for (long long i = 0; i < n; i++)
    {
        result += (maxi[i] - mini[i]);
    }

    return result;
}