// https://leetcode.com/problems/arranging-coins/

int arrangeCoins(int n)
{
    long low = 1, high = n, ans = -1;
    while (low <= high)
    {
        long mid = low + (high - low) / 2;
        if ((mid * (mid + 1)) / 2 > n)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return (int)ans;
}