#include <bits/stdc++.h>
using namespace std;
int targetsum(int ind, vector<int> &vec, vector<int> &res, int n, int sum, int target)
{
    // if(sum>target)return;
    if (ind >= n)
    {
        if (sum == target)
        {
            return 1;
        }
        return 0;
    }
    // PICK CASE
    res.push_back(vec[ind]);
    int pick = targetsum(ind + 1, vec, res, n, sum + vec[ind], target);
    // NOT PICK
    res.pop_back();
    int not_pick = targetsum(ind + 1, vec, res, n, sum, target);

    return pick+not_pick;
}

int main()
{
    vector<int> vec = {1, 2, 1};
    vector<int> res;
    int n = 3, target = 2, sum = 0;
    cout<<targetsum(0, vec, res, n, sum, target)<<endl;

    return 0;
}