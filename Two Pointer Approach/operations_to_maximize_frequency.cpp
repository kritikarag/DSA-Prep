// https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/description/
#include<bits/stdc++.h>
using namespace std;

int maxFrequencyScore(vector<int> &nums, long long k)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    // for(int i:prefix)cout<<i<<" ";
    // cout<<endl;
    long long left = 0, right = 0;
    long long result = 1;
    while (left <= right && right < n)
    {
        long long mid = (left + right) / 2;
        long long prev = abs((prefix[mid] - prefix[left]) - (mid - left) * nums[mid]);
        long long forw = abs((prefix[right + 1] - prefix[mid + 1]) - (right - mid) * nums[mid]);
        long long req = forw + prev;

        if (req <= k)
        {
            result = max(result, right - left + 1);
            right++;
        }
        else
            left++;
        if (left > right)
            right++;
    }
    return result;
}