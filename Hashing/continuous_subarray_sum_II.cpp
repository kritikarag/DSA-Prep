// https://leetcode.com/problems/continuous-subarray-sum/

bool checkSubarraySum(vector<int> &nums, int k)
{
    map<int, int> mp;
    int sum = 0, pretemp = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        sum = (sum + nums[i]) % k; // [edited]
        if (mp[sum])
            return true;
        mp[pretemp]++;
        pretemp = sum;
    }

    return false;
}