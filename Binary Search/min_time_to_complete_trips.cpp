// https://leetcode.com/problems/minimum-time-to-complete-trips/description/

long long minimumTime(vector<int> &time, int tt)
{
    long long left = 0, right = tt * (long long)time[0];
    long long res = right;
    while (left < right)
    {
        long long mid = left + (right - left) / 2;
        long long ans = 0;
        for (int i = 0; i < time.size(); i++)
        {
            ans += mid / time[i];
        }

        if (ans >= tt)
        {
            res = min(res, mid);
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return res;
}