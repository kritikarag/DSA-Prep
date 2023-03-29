// https://practice.geeksforgeeks.org/problems/839d6ba2c2e4c669ba9d9d9f32ad20118937284e/1

#include<bits/stdc++.h>
using namespace std;

int countSubstring(string str)
{
    // code here
    int count = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;

    int diff = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        diff += isupper(c) ? 1 : -1;
        if (mp[diff])
            count += mp[diff];
        mp[diff]++;
    }

    return count;
}
