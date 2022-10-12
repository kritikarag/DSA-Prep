//RECURSION
int frogJump(int n, vector<int>&heights){
    if(n==0)return 0;
    int steps = INT_MAX;
    for(int j=1;j<k;j++){
        if(n>=j){
            int jump = find(n - k, heights) + abs(heights[n] - height[n - j]);
            steps = min(steps, jump);
        }
    }
    return steps;
}

//MEMORIZATION
int frogJump(int n, vector<int>&heights, vector<int>&dp,int k){
    if(n==0)return 0;
    vector<int>dp(n,INT_MAX);
    if(dp[n]!=-1)return dp[n];
    for(int j=k;j>0;j--){
        if(n>=j)dp[n] = min(dp[n],frogJump(n-j,heights,dp,k)+abs(heights[n]-heights[n-j]));
    }
}

//TABULATION
int frogJump(int n , int heights[]){
    vector<int>dp(n,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        for(int j=k;j>0;j--){
            if(i>=j)dp[i]=min(dp[i],dp[i-j]+abs(heights[i]-heights[i-j]));
        }
    }
    return dp[n-1];
}

