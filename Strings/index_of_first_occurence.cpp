// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

int strStr(string hay, string need)
{
    int n = hay.length();
    int m = need.length();
    if (m == 0)
        return 0;
    int i, j;
    for (i = 0; i < n - m + 1; i++)
    {
        for (j = i; j < i + m; j++)
        {
            if (hay[j] != need[j - i])
                break;
        }
        if (j == i + m)
            return i;
    }
    return -1;
}