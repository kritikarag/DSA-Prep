// https://practice.geeksforgeeks.org/problems/3d49e4cce2820a813da02d1587c2dd9c542ce769/1

#include<bits/stdc++.h>
using namespace std;

int countSpecialNumbers(int N, vector<int> arr)
{
    // Code here
    unordered_map<int, int> mp;
    int maxi = INT_MIN;
    for (int i : arr)
    {
        maxi = max(i, maxi);
    }
    vector<bool> vis(maxi + 1, false);
    for (int i : arr)
    {
        if (mp[i] > 0)
        {
            mp[i]++;
            continue;
        }
        for (int j = 2 * i; j <= maxi; j += i)
        {
            vis[j] = true;
        }
        mp[i]++;
    }

    int ans = 0;
    for (int i : arr)
    {
        if (mp[i] > 1 || vis[i])
            ans++;
    }

    return ans;
}