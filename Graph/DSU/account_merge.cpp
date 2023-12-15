// https://leetcode.com/problems/accounts-merge/description/

#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sizes;

int find(int node)
{
    if (node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}

void combine(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    if (sizes[x] > sizes[y])
    {
        parent[y] = x;
        sizes[x] += sizes[y];
    }
    else
    {
        parent[x] = y;
        sizes[y] += sizes[x];
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    parent.resize(n + 1, 0);
    sizes.resize(n + 1, 1);

    unordered_map<string, int> mp;

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
    vector<vector<string>> result;
    vector<string> ans[n + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            string mail = accounts[i][j];

            if (mp.find(mail) != mp.end())
            {
                combine(i, mp[mail]);
            }
            else
            {
                mp[mail] = i;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        parent[i] = find(i);
    }

    for (auto it : mp)
    {
        string mail = it.first;
        int id = find(it.second);
        ans[id].push_back(mail);
    }

    for (int i = 0; i <= n; i++)
    {
        if (ans[i].size() == 0)
            continue;
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        sort(ans[i].begin(), ans[i].end());

        for (auto it : ans[i])
        {
            temp.push_back(it);
        }
        result.push_back(temp);
    }

    return result;
}