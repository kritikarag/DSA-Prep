// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

#include<bits/stdc++.h>
using namespace std;
bool isvowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
int maxVowels(string s, int k)
{
    int temp = 0, ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (isvowel(s[i]))
            temp++;
    }
    ans = temp;

    for (int i = k; i < s.length(); i++)
    {
        if (isvowel(s[i - k]))
            temp--;
        if (isvowel(s[i]))
            temp++;
        ans = max(ans, temp);
    }

    return ans;
}