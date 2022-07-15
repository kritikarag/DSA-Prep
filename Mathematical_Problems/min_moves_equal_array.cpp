int minMoves(vector<int>& nums) {
        int n= nums.size();
        int mini=nums[0],sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mini = min(mini,nums[i]);
        }
        return (sum-(n*mini));
    }
