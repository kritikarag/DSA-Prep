// https://leetcode.com/problems/optimal-partition-of-string/description/

#include<bits/stdc++.h>
using namespace std;

int partitionString(string s)
{
    int res = 0, n = s.length();
    unordered_map<char, int> mp;
    int i = 0;
    while (i < n)
    {
        if (mp[s[i]] > 0)
        {
            res++;
            mp.clear();
        }
        mp[s[i++]]++;
    }
    return res + 1;
}