// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

int findUnsortedSubarray(vector<int> &nums)
{
    int n = nums.size();
    int start = -1, end = -1;

    int maxi = nums[0], mini = nums[n - 1];

    for (int i = 1; i < n; i++)
    {
        if (maxi <= nums[i])
        {
            maxi = nums[i];
        }
        else
        {
            end = i;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (mini >= nums[i])
        {
            mini = nums[i];
        }
        else
        {
            start = i;
        }
    }

    if (start == -1 || end == -1)
        return 0;
    return end - start + 1;
}