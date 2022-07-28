int peakelement(vector<int>&nums){
    int low = 0, high = nums.size()-1;

    if(nums.size()==0||nums[0]>nums[1])return 0;
    if(nums[high]>nums[high-1])return high;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]>nums[mid+1])
            high = mid;
        else 
            low = mid+1;
    }
    return low;
}