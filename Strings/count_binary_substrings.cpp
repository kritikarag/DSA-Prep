// https://leetcode.com/problems/count-binary-substrings/description/

int countBinarySubstrings(string s)
{
    int curr = 1, prev = 0, res = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
            curr++;
        else
        {
            res += min(curr, prev);
            prev = curr;
            curr = 1;
        }
    }
    return res + min(curr, prev);
}