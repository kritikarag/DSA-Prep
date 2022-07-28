int findMin(vector<int> &nums)
{
    int n = nums.size();

    int low = 0, high = n - 1;
    if (nums[low] <= nums[high])
        return nums[low];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1])
            return nums[mid + 1];
        else if (nums[mid] < nums[mid - 1])
            return nums[mid];

        else if (nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int findMin(vector<int>&nums){
    int n=nums.size();

    int low=0,high=n-1;
    while(low<high){
        int mid= low+(high-low)/2;

        if(nums[mid]>nums[high])low=mid+1;
        else high = mid;
    }

    if(nums[low]<nums[high])return nums[low];
    else return nums[high];
}