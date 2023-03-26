// https://practice.geeksforgeeks.org/problems/5551749efa02ae36b6fdb3034a7810e84bd4c1a4/1
#include<bits/stdc++.h>
using namespace std;
int unvisitedLeaves(int N, int leaves, int frogs[])
{
    // Code here
    vector<bool> vis(leaves + 1, false);
    for (int i = 0; i < N; i++)
    {
        int curr = frogs[i];
        if (curr <= leaves && !vis[curr])
        {
            for (int j = curr; j <= leaves; j += curr)
            {
                vis[j] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= leaves; i++)
    {
        if (!vis[i])
            ans++;
    }

    return ans;
}