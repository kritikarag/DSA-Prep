//Minimum difference will be 0 when both the subsets will be divided into equal subsets
//Which means sum of subset1 will be <=sum/2
#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &vec, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += vec[i];

    int target = sum;

    vector < vector<bool>>dp(n, vector<bool>(target + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (vec[0] <= target)
        dp[0][vec[0]] = true;

    for (int i = 1; i < n; i++)
    { 
        for (int j = 1; j <= target; j++)
        {
            bool not_take = dp[i-1][j];
            bool take = false;
            
            if (vec[i] <= j)
                take = dp[i - 1][j - vec[i]];

            dp[i][j] = take||not_take;
        }
    }

    int mini = 1e9;
    for (int i = target/2;i>=0;i--)
    {
        if (dp[n - 1][i] == true)
        {
            //int diff = abs(i - (target - i));
            mini = abs(target - 2*i);
            break;
        }
    }

    return mini;
}

int minSubsetSumDifference(vector<int> &vec, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += vec[i];

    int target = sum;

    vector<bool> prev(target + 1, false);
    prev[0] = true;
    if (vec[0] <= target)
        prev[vec[0]] = true;

    for (int i = 1; i < n; i++)
    {
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for (int j = 1; j <= target; j++)
        {
            bool not_take = prev[j];
            bool take = false;
            if (vec[i] <= j)
                take = prev[j - vec[i]];

            curr[j] = take || not_take;
        }
        prev = curr;
    }

    int mini = INT_MAX;
    for (int i = target / 2; i >= 0; i--)
    {
        if (prev[i] == true)
        {
            mini = abs(target - 2 *i);
            break;
        }
    }

    return mini;
}

int main(){
    vector<int> arr = {1, 3, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);

    return 0;
}