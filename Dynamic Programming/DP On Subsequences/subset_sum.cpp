//RECURSION

bool subsetsum(int ind, int target, vector<int>&vec){
    if(target==0)return true;
    if(ind==0)return (vec[0]==target);

    bool not_take = subsetsum(ind-1,target,vec);
    bool take = false;
    if(vec[ind]<=target)take = subsetsum(ind-1,target-vec[ind],vec);

    return take||not_take;
}

//MEMORIZATION

bool subsetsum(int ind, int target, vector<int>&vec, vector<vector<int>>&dp){
    if(target==0)return true;
    if(ind ==0)return (vec[ind]==target);

    if(dp[ind][target]!=-1)return dp[ind][target];
    bool not_take = subsetsum(ind-1,target,vec,dp);
    bool take = false;
    if (vec[ind] <= target)
        take = subsetsum(ind - 1, target - vec[ind], vec);

    return dp[ind][target]= take||not_take;
}

//TABULATION

bool subsetsum(int target,vector<int>&vec){
    vector<vector<bool>dp(n+1,vector<bool>(target+1,false));

    for(int i=0;i<=n;i++)dp[i][0]=true;

    if(vec[0]<=target)dp[1][vec[0]]=true;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            //NOT TAKEN
            dp[i][j] =dp[i-1][j];
            //TAKEN
            if(vec[i-1]<=j)dp[i][j]|=dp[i-1][j-vec[i-1]];
        }
    }
    return dp[n][target];
}

//SPACE OPTIMIZATION

bool subsetsum(int target, vector<int>&vec){
    vector<bool>prev(target+1,false);

    prev[0]=true;
    if(vec[0]<=target)prev[vec[0]]=true;

    for (int i = 1; i < n; i++)
    {
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for (int j = 1; j <= target; j++)
        {
            // NOT TAKEN
            bool not_take = prev[j];
            // TAKEN
            bool take = false;
            if (vec[i] <= j)
                take = prev[j - vec[i]];

            curr[j] = take||not_take;
        prev = curr;
    }

    return prev[target];
}