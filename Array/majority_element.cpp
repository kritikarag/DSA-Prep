//METHOD 1 
int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         return nums[nums.size()/2];
    }

//METHOD 2
int majorityElement(vector<int> &nums)
{
    map<int, int> mp;
    int res = nums[0];
    mp[nums[0]]++;
    for (int i = 1; i < nums.size(); i++)
    {
        mp[nums[i]]++;
        if (mp[nums[i]] > mp[res])
            res = nums[i];
    }

    return res;
}

//METHOD 3 The Boyer-Moore voting algorithm

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
