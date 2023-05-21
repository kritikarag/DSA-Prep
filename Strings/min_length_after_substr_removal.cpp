// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/

#include<bits/stdc++.h>
using namespace std;
int minLength(string s)
{
    int i = 0;
    while (i < s.length() - 1 && s.length() > 1)
    {
        string temp = s.substr(i, 2);
        if (temp == "AB" || temp == "CD")
        {
            s.erase(i, 2);
            if (i > 0)
                i--;
            i--;
        }
        i++;
    }
    return s.length();
}