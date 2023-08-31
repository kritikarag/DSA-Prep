// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

vector<int> search(vector<int> &nums, int low, int high, int target)
{
    if (nums[low] == target && nums[high] == target)
        return {low, high};
    if (nums[low] <= target && target <= nums[high])
    {
        int mid = low + (high - low) / 2;
        vector<int> left = search(nums, low, mid, target);
        vector<int> right = search(nums, mid + 1, high, target);

        if (left[1] == -1)
            return right;
        if (right[0] == -1)
            return left;
        return {left[0], right[1]};
    }
    return {-1, -1};
}


vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n == 0)
    {
        return {-1, -1};
    }
    return search(nums, 0, n - 1, target);
}

// Approach 2

int findsmall(vector<int>& nums, int target){
        int ans = -1;

        int low = 0, high = nums.size() - 1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]==target){
                ans = mid;
                high = mid-1;
            }
            else if (nums[mid]>target){
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }

    int findbig(vector<int>& nums, int target){
        int ans = -1;

        int low = 0, high = nums.size() - 1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]==target){
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int small = findsmall(nums,target);
        int big = findbig(nums,target);

        ans.push_back(small);
        ans.push_back(big);

        return ans;
    }