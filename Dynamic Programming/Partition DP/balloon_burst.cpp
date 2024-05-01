// https://leetcode.com/problems/burst-balloons/description/

vector<vector<int>>dp;
int solve(int i,int j, vector<int>&nums){
    if(i>j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int result = 0;
    for(int k=i;k<=j;k++){
        result = max(result, nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums)+solve(k+1,j,nums));
    } 

    return dp[i][j] = result;

}
int maxCoins(vector<int>& nums) {
   n = nums.size();
   nums.insert(nums.begin(),1);
   nums.push_back(1);
    dp.resize(n+1,vector<int>(n+1,-1));
   return solve(1,n,nums); 
}

int maxCoins(vector<int>& nums) {
    n = nums.size();
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    dp.resize(n+2,vector<int>(n+2,0));
    
    for(int i=n;i>0;i--){
        for(int j=1;j<=n;j++){
            if(i>j)continue;
            int result = 0;
            for(int k = i; k<=j;k++){
                result = max(result, nums[k]*nums[i-1]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
            }
            dp[i][j] = result;
        }
    }
    //return solve(1,n,nums); 
    return dp[1][n];
}
