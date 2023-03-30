// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include<bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k)
{
    queue<pair<long long int, long long int>> q;
    vector<long long> ans;
    for (long long int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            q.push({i, arr[i]});
    }

    if (!q.empty())
        ans.push_back(q.front().second);
    else
        ans.push_back(0);

    for (long long int i = k; i < n; i++)
    {
        if (!q.empty() && q.front().first == i - k)
            q.pop();
        if (arr[i] < 0)
            q.push({i, arr[i]});
        if (q.empty())
            ans.push_back(0);
        else
            ans.push_back(q.front().second);
    }
    return ans;
}