// https://leetcode.com/problems/factorial-trailing-zeroes/description/

int trailingZeroes(int n)
{
    int count = 0;
    for (long long i = 5; n / i; i *= 5)
        count += n / i;
    return count;
}