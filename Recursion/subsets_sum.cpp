// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

#include<bits/stdc++.h>
using namespace std;

void calculate(int i, int sum, vector<int> &arr, vector<int> &res)
{
    if (i == arr.size())
    {
        res.push_back(sum);
        return;
    }

    calculate(i + 1, sum + arr[i], arr, res);
    calculate(i + 1, sum, arr, res);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> res;
    calculate(0, 0, arr, res);
    return res;
}