//

//Naive Approach

int findDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1])return nums[i];
    }

    return -1;
}

//Time Complexity Optimized
int findDuplicate(vector<int>& nums) {
    map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        if(mp[nums[i]]>0)return nums[i];
        mp[nums[i]]++
    }   

    return -1;
}

int findDuplicate(vector<int>& nums) {
       int slow = nums[0], fast = nums[0];
       do
       {
        slow = nums[slow];
        fast = nums[fast];
       } while (slow!=fast);
       
       fast = nums[0];

       while (slow!=fast)
       {
        slow = nums[slow];
        fast = nums[fast];
       }
       return slow;
}