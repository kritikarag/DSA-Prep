// https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include<bits/stdc++.h>
using namespace std;


// Needs changes
int characterReplacement(string s, int k)
{
    int n = s.length();
    int ans = 0, start = 0;
    map<int, int> mp;
    int maxi = 0;
    char mostfreq;
    // vector<int>intial(26,0);
    for (int i = 0; i < n; i++)
    {
        // int start = vec[s[i]-'A'];
        mp[s[i]]++;
        if (mp[s[i]] > maxi)
        {
            maxi = mp[s[i]];
            mostfreq = s[i];
        }
        cout << start << " " << (i - start + 1 - mp[mostfreq]) << endl;
        while ((i - start + 1 - mp[mostfreq]) > k)
        {
            mp[start]--;
            if (mp[start] > mp[mostfreq])
            {
                maxi = mp[start];
                mostfreq = s[i];
            }
            start++;
        }
        ans = max(ans, i - start + 1);
        cout << start << " " << ans << endl;
    }
    return ans;
}


// Working One

int characterReplacement(string s, int k)
{
    int n = s.length();
    int ans = 0, start = 0;
    unordered_map<int, int> mp;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        // int start = vec[s[i]-'A'];
        mp[s[i]]++;
        maxi = max(maxi, mp[s[i]]);
        // cout<<start<<" "<<(i-start+1-maxi)<<endl;
        if ((i - start + 1 - maxi) > k)
        {
            mp[s[start]]--;
            start++;
        }
        else
            ans = max(ans, i - start + 1);
        cout << start << " " << ans << endl;
    }
    return ans;
}