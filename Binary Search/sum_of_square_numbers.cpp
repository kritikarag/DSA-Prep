// https://leetcode.com/problems/sum-of-square-numbers/

bool isPerfectSquare(int num)
{
    long long low = 1, high = num;
    while (low <= high)
    {
        long long int mid = low + (high - low) / 2;
        if (mid * mid == num)
            return true;
        else if (mid * mid < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}
bool judgeSquareSum(int c)
{
    if (c == 0)
        return true;
    for (long long i = 0; i * i <= c; i++)
    {
        long long req = c - i * i;
        if (isPerfectSquare(req))
            return true;
    }

    return false;
}


//Method 2

bool judgeSquareSum(int c)
{
    if (c < 3)
        return true;
    long long int a = 0, b = sqrt(c);
    while (a <= b)
    {
        if (a * a + b * b == c)
        {
            return true;
        }
        else if (a * a + b * b < c)
        {
            a++;
        }
        else
        {
            b--;
        }
    }
    return false;
