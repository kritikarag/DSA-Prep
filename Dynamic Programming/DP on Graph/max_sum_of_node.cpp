// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/

# Since the graph is undirected there will always exist edges between any two nodes. We just need to find the xor of maximum sum nodes and keep a track that at the end number of nodes picked is even since we will be pick up edges.
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
