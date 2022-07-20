int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1, 0));
        
        for(int ind=nums.size()-1; ind>=0; ind--){
            for(int prev=ind-1; prev>=-1; prev--){
                int take=0;
                if(prev==-1 || nums[prev]<nums[ind])
                    take = 1+dp[ind+1][ind+1];
                int not_take = dp[ind+1][prev+1];
                dp[ind][prev+1] = max(take, not_take);
            }
        }
        return dp[0][0];
    }
