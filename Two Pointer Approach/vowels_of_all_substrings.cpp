// https://leetcode.com/problems/vowels-of-all-substrings/

#include<bits/stdc++.h>
using namespace std;

bool check(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
long long countVowels(string word)
{
    int n = word.length();
    vector<int> vowels;

    long long ans = 0;
    long long count = 0;

    for (int i = 0; i < n; i++)
    {
        // vowels[i+1] = vowels[i]+1;
        if (check(word[i]))
        {
            vowels.push_back(i);
        }
    }
    for (int i = 0; i < vowels.size(); i++)
    {
        ans += (vowels[i] + 1) * (n - vowels[i]);
    }

    return ans;
}