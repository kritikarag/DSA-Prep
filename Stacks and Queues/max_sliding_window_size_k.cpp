// https://leetcode.com/problems/sliding-window-maximum/

#include<bits/stdc++.h>
using namespace std;

//O(N)
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 1 || k == 1)
        return nums;
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
        {
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}


//O(NlogK)

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 1 || k == 1)
        return nums;
    int max1 = INT_MIN, max2 = INT_MIN;
    vector<int> ans;
    // int i;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push({nums[i], i});
    }
    ans.emplace_back(pq.top().first);
    for (int i = k; i < n; i++)
    {
        while (pq.top().second <= i - k)
            pq.pop();
        pq.push({nums[i], i});
        ans.emplace_back(pq.top().first);
    }

    return ans;
}