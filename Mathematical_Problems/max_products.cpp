int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        size_t n=nums.size();
        
        int res1= nums[0] * nums[1] * nums[2];
        int res2= nums[0] * nums[n-1]* nums[n-2];
        
        return max(res1,res2);
    }
