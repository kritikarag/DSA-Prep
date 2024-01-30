// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s)
{
    map<char, int> mp;
    int left = 0, ans = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;

        while (mp.size() == 3)
        {
            ans += n - i;
            mp[s[left]]--;
            if (mp[s[left]] == 0)
                mp.erase(s[left]);
            left++;
        }
    }

    return ans;
}