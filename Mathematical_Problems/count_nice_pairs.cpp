// https://leetcode.com/problems/count-nice-pairs-in-an-array/

int reverse(int num)
{
    int rev = 0;
    while (num)
    {
        rev = rev * 10 + (num % 10);
        num /= 10;
    }
    return rev;
}

int countNicePairs(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int res = 0, mod = 1e9 + 7;
    for (int i : nums)
    {
        int rev = reverse(i);
        res = (res + mp[i - rev]++) % mod;
    }
    return res;
}