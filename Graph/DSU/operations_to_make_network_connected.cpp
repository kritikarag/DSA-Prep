// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include<bits/stdc++.h>
using namespace std;

int find(int node, vector<int> &parent)
{
    if (node == parent[node])
        return node;
    return parent[node] = find(parent[node], parent);
}

void combine(int x, int y, vector<int> &parent, vector<int> &rank)
{
    x = find(x, parent);
    y = find(y, parent);

    if (x == y)
        return;

    if (rank[x] > rank[y])
    {
        parent[y] = x;
        rank[x] += rank[y];
    }
    else
    {
        parent[x] = parent[y];
        rank[y] += rank[x];
    }
}

int makeConnected(int n, vector<vector<int>> &conns)
{
    vector<int> parent(n), rank(n, 1);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < conns.size(); i++)
    {
        combine(conns[i][0], conns[i][1], parent, rank);
    }

    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        int par = find(i, parent);
        if (mp.find(par) == mp.end())
        {
            mp[par] = {};
        }
        if (par == i)
            continue;
        mp[par].push_back(i);
    } 

    int req = mp.size() - 1;

    int used = 0;
    for (auto it : mp)
    {
        used += it.second.size();
    }

    return (req + used) > conns.size() ? -1 : req;
}