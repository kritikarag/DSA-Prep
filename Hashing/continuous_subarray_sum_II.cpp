// https://leetcode.com/problems/continuous-subarray-sum/

bool checkSubarraySum(vector<int> &nums, int k)
{
    map<int, int> mp;
    int sum = 0, pretemp = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = (sum + nums[i]) % k; // [edited]
        if (mp[sum])
            return true;
        mp[pretemp]++;
        pretemp = sum;
    }

    return false;
}

Optimized Version :

bool checkSubarraySum(vector<int> &nums, int k)
{
    int prefSum = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        prefSum += nums[i];
        prefSum %= k;

        if (prefSum == 0 && i)
            return true;

        if (mp.find(prefSum) != mp.end())
        {
            if (i - mp[prefSum] > 1)
                return true;
        }
        else
            mp[prefSum] = i;
    }

    return false;
}