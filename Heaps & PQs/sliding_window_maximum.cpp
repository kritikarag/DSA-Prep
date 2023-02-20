// https://leetcode.com/problems/sliding-window-maximum/description/

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 1 || k == 1)
        return nums;
    int max1 = INT_MIN, max2 = INT_MIN;
    vector<int> ans;

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