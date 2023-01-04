// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

int numberOfSubstrings(string s)
{
    map<char, int> mp;
    int left = 0, count = 0, right = s.length() - 1;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
        while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0)
        {
            count += 1 + right - i;
            mp[s[left++]]--;
        }
    }

    return count;
}
