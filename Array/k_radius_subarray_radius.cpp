// https://leetcode.com/problems/k-radius-subarray-averages/description/

vector<int> getAverages(vector<int> &nums, int k)
{
    int n = nums.size();
    long long start = 2 * k, sum = 0;
    vector<int> res(n, -1);
    if (k >= n)
        return res;
    for (int i = 0; i < start; i++)
    {
        sum += nums[i];
    }
    for (int i = start; i < n; i++)
    {
        sum += nums[i];
        res[i - k] = (sum / (start + 1));
        sum -= nums[i - start];
    }
    return res;
}