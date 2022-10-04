// https://leetcode.com/problems/arranging-coins/

int arrangeCoins(int n)
{
    int mask = 1 << 15;
    long result = 0;
    while (mask)
    {
        result |= mask;
        if ((result * (result + 1)) / 2 > n)
        {
            result ^= mask;
        }
        mask >>= 1;
    }
    return (int)result;
}