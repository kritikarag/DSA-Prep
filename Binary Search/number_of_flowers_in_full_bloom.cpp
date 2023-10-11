// https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/

#include<bits/stdc++.h>
using namespace std;
vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
{
    vector<int> start, end;
    for (auto &t : flowers)
        start.push_back(t[0]), end.push_back(t[1]);
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    vector<int> res;
    for (int t : people)
    {
        int started = upper_bound(start.begin(), start.end(), t) - start.begin();
        int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
        res.push_back(started - ended);
    }
    return res;
}