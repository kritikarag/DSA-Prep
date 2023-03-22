// https://leetcode.com/problems/valid-perfect-square/

//METHOD 1
bool isPerfectSquare(int num)
{
    int low = 1, high = num;
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


//METHOD 2
bool isPerfectSquare(int num)
{
    int a = 1;
    while (num > 0)
    {
        num = num - a;
        a = a + 2;
    }
    return num == 0;
}