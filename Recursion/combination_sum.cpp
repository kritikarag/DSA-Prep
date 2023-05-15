// https://leetcode.com/problems/combination-sum/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
void calculate(int i, int sum, vector<int> &can, vector<int> &curr, int target)
{
    if (sum == target)
    {
        if (find(res.begin(), res.end(), curr) != res.end())
            return;
        res.push_back(curr);
        return;
    }
    if (i >= can.size() || sum > target)
        return;

    calculate(i + 1, sum, can, curr, target);
    curr.push_back(can[i]);
    calculate(i, sum + can[i], can, curr, target);
    calculate(i + 1, sum + can[i], can, curr, target);
    curr.pop_back();
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> curr;
    calculate(0, 0, candidates, curr, target);
    return res;
}
