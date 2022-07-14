void moveZeroes(vector<int>& nums) {
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)zero++;
            else nums[i-zero]=nums[i];
        }
        for(int i=nums.size()-zero;i<nums.size();i++){
            nums[i]=0;
        }
        
    }
