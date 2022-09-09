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
    vector<vector<bool>dp(n,vector<bool>(target+1,false));

    for(int i=0;i<=target;i++)dp[0][i]=false;
    for(int i=0;i<n;i++)dp[i][0]=true;

    if(vec[0]<=target)dp[0][vec[0]]=true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            //NOT TAKEN
            dp[i][j] =dp[i-1][j];
            //TAKEN
            if(vec[i]<=j)dp[i][j]|=dp[i-1][j-vec[i]];
        }
    }

    return dp[n-1][target];
}