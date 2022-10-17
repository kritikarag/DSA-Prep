
// RECURSION
int countSubsets(vector<int> &vec, int i, int target)
{
    if(target==0)return 1;
    if(i==0){
        return (vec[i]==target);
    }
    int not_take = countSubsets(vec,i-1,target);
    int take = 0;
    if(vec[i]<=target)take=countSubsets(vec,i-1,target-vec[i]);

    return not_take + take;
}

//MEMORIZATION

int countSubsets(vector<int> &vec, int i, int target, vector<vector<int>>&dp)
{
    if(target==0)return 1;
    if(i==1)return (vec[i-1]==target);

    if(dp[i][target]!=-1)return dp[i][target];

    int not_take = countSubsets(vec,i-1,target,dp);
    int take =0;
    if(vec[i-1]<=target)take = countSubsets(vec,i-1,target-vec[i-1],dp);

    return dp[n][target];
}

//TABULATION

int countSubsets(vector<int>&vec, int n, int target){
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    for(int i=0;i<=n;i++)dp[i][0] = 1;
    if(vec[0]<=target) dp[1][vec[0]] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            int not_take = dp[i-1][j];
            int take = 0;
            if(vec[i-1]<=j)take = dp[i-1][j-vec[i-1]];

            dp[i][j] = take + not_take;
        }
    }

    return dp[n][target];
}

// Space Optimized

int countSubsets(vector<int> &vec, int n, int target)
{
    vector<int>prev(target+1,0);
    prev[0]=1;
    for(int i=1;i<=n;i++){
        vector<int>curr(target+1,0);
        curr[0]=1;
        for(int j=1;j<=target;j++){
            int not_take = prev[j];
            int take = 0;
            if(vec[i-1]<=j)take = prev[j-vec[i-1]];
            curr[j] = take + not_take;
        }
        prev = curr;
    }
    return prev[n];
}