// https://leetcode.com/problems/next-greater-element-ii/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = n * 2 - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }
        if (!st.empty())
            ans[i % n] = st.top();
        st.push(nums[i % n]);
    }

    return ans;
}