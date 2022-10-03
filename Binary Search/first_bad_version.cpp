// https://leetcode.com/problems/first-bad-version/

int firstBadVersion(int n)
{
    int low = 1, high = n, ans;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int firstBadVersion(int n)
{
    int low = 1, high = n;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}