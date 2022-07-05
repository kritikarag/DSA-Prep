int sum=0;
    void solve(TreeNode* root, int low, int high){
        if(!root)return;
        
        solve(root->left,low,high);
        solve(root->right,low,high);
        if(root->val>=low and root->val<=high){
            sum+=root->val;
        }
        return;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        solve(root,low,high);
        return sum;
    }
