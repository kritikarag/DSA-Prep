// https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/

int minOperations(vector<int> &nums, vector<int> &div)
{
    sort(nums.begin(), nums.end());
    int g = div[0];
    for (int i = 1; i < div.size(); i++)
    {
        g = __gcd(div[i], g);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (g % nums[i] == 0)
            return i;
    }
    return -1;
}