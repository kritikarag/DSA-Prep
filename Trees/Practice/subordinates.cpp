// https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>
using namespace std;

// Time Limit Exceeded
void dfs(int node, vector<int> adj[], int &res)
{

    for (int i : adj[node])
    {
        res++;
        dfs(i, adj, res);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1), adj[n + 1];
    ans[0] = 0;
    ans[1] = n - 1;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    for (int i = 2; i <= n; i++)
    {
        if (adj[i].size() == 0)
            continue;
        int res = 0;
        dfs(i, adj, res);
        ans[i] = res;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

// Accepted, Fucking so proud of myself

int dfs(int node, vector<int> adj[], vector<int> &ans, int res)
{

    if (adj[node].size() == 0)
        return 0;
    for (int i : adj[node])
    {
        // res++;
        ans[node] += 1 + dfs(i, adj, ans, res);
        // ans[node] += res;
    }
    return ans[node];
}
int main()
{
    int n;
    cin >> n;
    
    vector<int> ans(n + 1), adj[n + 1];
    ans[0] = 0;
    ans[1] = n - 1;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    for (int i : adj[1])
    {
        int res = 0;
        dfs(i, adj, ans, res);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}