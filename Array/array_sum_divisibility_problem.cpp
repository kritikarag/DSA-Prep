// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

bool canPair(vector<int> nums, int k)
{
    // Code here.
    if (nums.size() % 2 != 0)
        return false;
    unordered_map<int, int> mp;
    for (auto val : nums)
        mp[val % k]++;

    for (auto it : mp)
    {
        int val1 = it.first;
        int val2 = abs(k - it.first);

        if (val1 == 0 and mp[val1] % 2 == 0)
            continue;

        if (mp.find(val2) == mp.end())
            return false;
        if (mp[val1] != mp[val2])
            return false;
    }
    return true;
}