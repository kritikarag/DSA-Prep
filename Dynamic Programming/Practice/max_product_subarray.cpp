// https://leetcode.com/problems/maximum-product-subarray/description/

/*A way to understand the reason why the maximum subarray must be a prefix of suffix of the array:
suppose there's no 0 in the array:

if number of negative number is odd, and left most is i and right most is j,
then we can only either keep A[:j] or A[i+1:] to make it max
if it's even, then we just multiply all the numbers.
0 will divide the array to several separated subarrays*/

int maxProduct(vector<int> A)
{
    int n = A.size(), res = A[0], l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        l = (l ? l : 1) * A[i];
        r = (r ? r : 1) * A[n - 1 - i];
        res = max(res, max(l, r));
    }
    return res;
}



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


