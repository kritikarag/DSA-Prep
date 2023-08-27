// https://leetcode.com/problems/minimum-operations-to-form-subsequence-with-target-sum/description/

int minOperations(vector<int> &nums, int target)
{
    long long int sum = 0;
    priority_queue<int> pq;
    for (int i : nums)
    {
        sum += i;
        pq.push(i);
    }

    if (sum == target)
        return 0;
    if (sum < target)
        return -1;

    int res = 0;

    while (target > 0)
    {
        int curr = pq.top();
        pq.pop();
        if ((sum - curr) >= target)
        {
            sum -= curr;
        }
        else if (curr <= target)
        {
            target -= curr;
            sum -= curr;
        }
        else
        {
            pq.push(curr / 2);
            pq.push(curr / 2);
            res++;
        }
    }
    return res;
}