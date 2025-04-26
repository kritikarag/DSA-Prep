// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long n = nums.size(), ans = 0;
    int mini = -1, maxi = -1, bad = -1;
  
    for(int i=0;i<n;i++){
        if(minK == nums[i])mini = i;
        if(maxK == nums[i])maxi = i;
  
        if(nums[i]>maxK || nums[i]<minK)bad = i;
  
        ans+=max(0, min(mini,maxi)-bad);
    }
  
    return ans;
  }
