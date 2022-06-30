//METHOD 1 
int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         return nums[nums.size()/2];
    }



int majorityElement(vector<int>& nums) {
        int major=nums[0], count = 1;
        for(int i=1; i<nums.size();i++){
            if(count==0){
                count++;
                major=nums[i];
            }else if(major==nums[i]){
                count++;
            }else count--;
            
        }
        return major;
    }
