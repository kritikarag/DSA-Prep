// https://leetcode.com/problems/number-of-provinces/

#include<bits/stdc++.h>
using namespace std;

int find(int node, vector<int> &parent)
{
    if (node == parent[node])
    {
        return node;
    }

    return parent[node] = find(parent[node], parent);
}

void combine(int x, int y, vector<int> &parent, vector<int> &size)
{
    x = find(x, parent);
    y = find(y, parent);

    if (x == y)
        return;

    if (size[x] > size[y])
    {
        parent[y] = x;
        size[x] += size[y];
    }
    else
    {
        parent[x] = y;
        size[y] += size[x];
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> parent(n), size(n, 1);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1)
            {
                combine(i, j, parent, size);
            }
        }
    }

    unordered_set<int> st;
    for (int i : parent)
    {
        i = find(i, parent);
        st.insert(i);
    }

    return st.size();
}