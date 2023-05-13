// https://leetcode.com/problems/find-the-difference/

#include<bits/stdc++.h>
using namespace std;

char findTheDifference(string s, string t)
{
    char res = '\0';
    for (char c : s)
        res ^= c;
    for (char c : t)
        res ^= c;
    return res;
}