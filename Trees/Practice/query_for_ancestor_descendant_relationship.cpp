//

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &in, vector<int> &out, vector<int> tree[], int &time)
{

    in[node] = time++;
    for (int i : tree[node])
    {
        if (i != parent)
            dfs(i, node, in, out, tree, time);
    }
    out[node] = time++;
}

bool check(int u, int v, vector<int> &in, vector<int> &out)
{
    return (in[u] <= in[v] && out[v] <= out[u]);
}
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> tree[n];
    vector<int> in(n, -1), out(n, -1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int time = 0;
    dfs(0, -1, in, out, tree, time);
    // for(int i=0;i<n;i++){
    //     cout<<"Node"<<i<<": "<<in[i]<<" "<<out[i]<<endl;
    // }
    for (int i = 0; i < q; i++)
    {
        int q1, q2;
        cin >> q1 >> q2;
        if (check(q1, q2, in, out))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}