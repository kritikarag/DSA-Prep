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


// LinkedList Approach

TreeNode *solve(int i, int j, vector<int> &nums)
{
    if (i > j)
        return NULL;
    int mid = i + (j - i) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = solve(i, mid - 1, nums);
    root->right = solve(mid + 1, j, nums);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();
    return solve(0, n - 1, nums);
}
