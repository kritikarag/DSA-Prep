//
WRONG

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
map<int, int> mp;
vector<int> res;
set<int> s;
int len = 0, index;
int solve(int prev, int curr, vector<int> &nums)
{
    if (curr >= nums.size())
        return 0;
    if (dp[prev + 1][curr] != -1)
        return dp[prev + 1][curr];

    int take = 0;

    if (prev == -1 || nums[curr]%nums[prev] == 0)
    {
        take = 1 + solve(curr, curr + 1, nums);
    }

    int not_take = solve(prev, curr + 1, nums);

    return dp[prev + 1][curr] = max(take, not_take);
}
vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return nums;
    sort(nums.begin(), nums.end());
    dp.resize(n, vector<int>(n, -1));

    int ans = solve(-1, 0, nums);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // for(int i=n-2;i>=0;i--){
    //     for(int j=n-1;j>=0;j--){
    //         if()
    //     }
    // }
    // if(dp[0][0]-1==dp[0][1])res.push_back(nums[0]);
    // for(int i=1;i<n;i++){
    //     if(dp[0][i]==dp[0][i-1]-1){
    //         res.push_back(nums[i]);
    //     }
    // }
    // cout<<index<<endl;

    vector<int> temp = dp[0];
    int index = n - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i+1; j <n; j++)
        {
            if (nums[j] % nums[i] == 0 && dp[i][i] < dp[i-1][j] + 1)
            {
                mp[i] = j;
                // if (temp[index] < temp[i])
                // {
                //     index = i;
                // }
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        if(dp[0][i]>dp[0][index]){
            index = i;
        }
    }
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    res.push_back(nums[index]);
    while (mp.find(index) != mp.end())
    {
        res.push_back(nums[mp[index]]);
        index = mp[index];
    }
    if (res.size() == 0)
        res.push_back(nums[0]);
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];

    vector<int>res = largestDivisibleSubset(vec);

    for(int i:res)cout<<i<<" ";

    return 0;
}