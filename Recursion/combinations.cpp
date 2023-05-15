// https://leetcode.com/problems/combinations/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
void calculate(int i, vector<int> &curr, int n, int k)
{
    if (curr.size() == k)
    {
        res.push_back(curr);
        return;
    }

    if (i > n)
        return;

    calculate(i + 1, curr, n, k);
    curr.push_back(i);
    calculate(i + 1, curr, n, k);
    curr.pop_back();
}
vector<vector<int>> combine(int n, int k)
{
    vector<int> curr;
    calculate(1, curr, n, k);
    return res;
}