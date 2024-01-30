// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include<bits/stdc++.h>
using  namespace std;

int maxScore(vector<int> &cp, int k)
{
    int n = cp.size();
    int sum = 0;
    for (int i : cp)
        sum += i;

    int curr = 0, minsum = 0;
    int x = n - k; // the amount of cards we don't need to select
    for (int i = 0; i < x; i++)
        curr += cp[i];
    minsum = curr;
    for (int i = x; i < n; i++)
    {
        curr += cp[i];
        if (i >= x)
            curr -= cp[i - x];
        minsum = min(minsum, curr);
    }
    cout << minsum << endl;
    return sum - minsum;
}