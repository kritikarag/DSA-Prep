// https://leetcode.com/problems/sqrtx/

int mySqrt(int x)
{
    long long low = 0, high = x;
    long long ans;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (mid * mid == x)
            return mid;
        else if (mid * mid < x)
        {
            low = mid + 1;
            ans = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}