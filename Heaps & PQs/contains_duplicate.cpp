//Using Maps

bool containsDuplicate(vector<int> &nums)
{
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
        if (mp[nums[i]] > 1)
            return true;
    }

    return false;
}
//Using Sets

bool containsDuplicate(vector<int> &nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
        s.insert(nums[i]);

    return !(nums.size() == s.size());
}