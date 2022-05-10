void solve(int i,int j,vector<int>&nums, vector<int>&ans){
        if(i<=j){
            int mid = i +(j-i)/2;
            ans.push_back(nums[mid]);
            solve(i,mid-1,nums,ans);
            solve(mid+1,j,nums,ans);
        }
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        int n=nums.size();
        vector<int>ans;
        solve(0,n-1,nums,ans);
        return ans;
    }
