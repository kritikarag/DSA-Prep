// https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

#include<bits/stdc++.h>
using namespace std;

int calculate(vector<int> graph[], int node, vector<int> &time)
{
    if (graph[node].size() == 0)
        return 0;
    int temp = 0;
    for (int i = 0; i < graph[node].size(); i++)
    {
        temp = max(temp, time[node] + calculate(graph, graph[node][i], time));
    }
    return temp;
}
int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &time)
{
    queue<int> q;
    vector<int> graph[n];

    vector<bool> inform(n, false);
    for (int i = 0; i < n; i++)
    {
        if (manager[i] == -1)
        {
            inform[i] = true;
            q.push(i);
        }
        else
        {
            graph[manager[i]].push_back(i);
        }
    }

    int ans = 0;

    for (int i = 0; i < graph[headID].size(); i++)
    {
        ans = max(ans, time[headID] + calculate(graph, graph[headID][i], time));
    }

    return ans;
}