void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)zero++;
            else if(nums[i]==1)one++;
            else two++;
        }
        
        int j=0;
        while(zero--)nums[j++]=0;
        while(one--)nums[j++]=1;
        while(two--)nums[j++]=2;
    }
