// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description

//Since the graph is undirected so there will always be a path b/w any 2 nodes
// All we need to ensure is that number of nodes being XORed by k is even.

vector<vector<long long>>dp;
long long solve(int index, bool even, int k, vector<int>&nums){
    if(index>=nums.size()){
        return (even)?0:-1e9;
    }

    if(dp[index][even]!=-1)return dp[index][even];

    long long take = (nums[index]^k) + solve(index+1, even^1, k, nums);
    long long not_take = nums[index] + solve(index+1, even, k, nums);

    return dp[index][even] = max(take, not_take);
}
long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    int n = nums.size();
    dp.resize(n,vector<long long>(2,-1));
    return solve(0,true,k,nums);
}
