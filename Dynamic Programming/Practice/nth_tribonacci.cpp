// https://leetcode.com/problems/n-th-tribonacci-number/description/

int tribonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    if (n == 2)
        return 1;
    int prev1 = 1, prev2 = 1, prev3 = 0, res;
    for (int i = 3; i <= n; i++)
    {
        res = prev1 + prev2 + prev3;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = res;
    }
    return res;
}
