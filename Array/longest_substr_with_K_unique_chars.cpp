// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

int longestKSubstr(string s, int k)
{
    // your code here
    int start = 0;
    unordered_map<char, int> mp;

    int ans = -1;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;

        while (mp.size() > k)
        {
            mp[s[start]]--;
            if (mp[s[start]] == 0)
            {
                mp.erase(s[start]);
            }
            start++;
        }

        if (mp.size() == k)
        {
            ans = max(ans, i - start + 1);
        }
    }

    return ans;
}