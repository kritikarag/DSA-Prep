#include<bits/stdc++.h>
using namespace std;

// RECURSION

int maxLength(int ind, int prev,int n, vector<int>&vec){
    if(ind==n)return 0;
    int not_take = maxLength(ind+1,prev,n,vec);
    int take = 0;
    if(prev==-1||vec[ind]>vec[prev]){
        take = 1 + maxLength(ind+1,ind,n,vec);
    }

    return max(take,not_take);
}

int longestIncreasingSubsequence(vector<int>&vec, int n)
{ 
    return maxLength(0, -1, n , vec);
}

// MEMORIZATION

int maxLength(int ind, int prev, int n, vector<int> &vec, vector<vector<int>>&dp){
    if(ind==n)return 0;
    if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];

    int not_take = maxLength(ind + 1, prev, n, vec,dp);
    int take = 0;
    if (prev == -1 || vec[ind] > vec[prev])
    {
        take = 1 + maxLength(ind + 1, ind, n, vec, dp);
    }

    return dp[ind][prev+1] = max(take, not_take);
}

    int longestIncreasingSubsequence(vector<int>&vec, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return maxLength(0, -1, n, vec, dp);
}

//TABULATION

int longestIncreasingSubsequence(vector<int>&vec, int n){
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int ind =n-1;ind>=0;ind--){
        for(int prev =ind-1;prev>=-1;prev--){
            int not_take = dp[ind+1][prev+1];
            int take = 0;
            if (prev == -1 || vec[ind] > vec[prev])
            {
                take = 1 + dp[ind+1][ind+1];
            }
            dp[ind][prev + 1] = max(take, not_take);
        }
    }
    return dp[0][0]; 
}

//SPACE OPTIMIZATION

int longestIncreasingSubsequence(vector<int> &vec, int n)
{
    vector<int> ahead(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int not_take = ahead[prev + 1];
            int take = 0;
            if (prev == -1 || vec[ind] > vec[prev])
            {
                take = 1 + ahead[ind + 1];
            }
            curr[prev + 1] = max(take, not_take);
        }
        ahead = curr;
    }
    return ahead[0];
}

// Binary Search

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;
    temp.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }
    return temp.size();
}

int main()
{

    vector<int>vec = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = vec.size();

    cout << "The length of the longest increasing subsequence is "
         << longestIncreasingSubsequence(vec, n);

    return 0;
}