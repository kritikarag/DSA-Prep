int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int mini=nums[0],maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)swap(mini,maxi);
            
            mini = min(nums[i],mini*nums[i]);
            maxi = max(nums[i],maxi*nums[i]);
            
            res=max(res,maxi);
        }
        
        return res;
    }
