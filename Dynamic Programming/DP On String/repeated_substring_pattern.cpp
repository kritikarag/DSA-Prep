// https://leetcode.com/problems/repeated-substring-pattern/description/

#include<bits/stdc++.h>
using namespace std;

bool check(string pat, string s)
{
    int m = pat.length(), n = s.length();
    int i = 0;
    while (i < n)
    {
        string temp = s.substr(i, m);
        if (temp != pat)
            return false;
        i += m;
    }
    return true;
}
bool repeatedSubstringPattern(string s)
{
    int n = s.length(), maxi = 0;
    vector<int> lps(n, 0);
    int i = 1, len = 0;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            lps[i++] = ++len;
        }
        else
        {
            if (len > 0)
            {
                len = lps[len - 1];
            }
            else
            {
                i++;
            }
        }
    }

    if (lps[n - 1] == 0)
        return false;
    string req = s.substr(0, n - lps[n - 1]);
    if (check(req, s))
        return true;
    else
        return false;
}
