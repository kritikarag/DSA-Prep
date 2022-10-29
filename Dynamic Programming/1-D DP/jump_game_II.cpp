// https://leetcode.com/problems/jump-game-ii/

int jump(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int pos = nums[0], curr = nums[0];
    int steps = 1;
    for (int i = 1; i <= min(n - 1, pos); i++)
    {
        curr = max(curr, nums[i] + i);
        if (i == n - 1)
            return steps;
        if (i == pos)
        {
            pos = curr;
            steps++;
        }
    }
    return 0;
}