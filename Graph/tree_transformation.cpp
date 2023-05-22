// https://practice.geeksforgeeks.org/problems/fbcd1787378ed396a8f24b47872cbc0ad2624f1d/1
#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> p)
{
    // code here
    int ans = n - 1;
    vector<int> degree(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        degree[p[i]]++;
        degree[i]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
            ans--;
    }

    return (ans <= 0 ? 0 : ans);
}