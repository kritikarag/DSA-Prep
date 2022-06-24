bool ans = false;

	void path(TreeNode* root,int target){
		if(!root)return ;
		target -= root->val;
		path(root->left,target);
		path(root->right,target);
		if(target == 0 && !root->left && !root->right)ans=true;
	}
    bool hasPathSum(TreeNode* root, int targetSum) {
        path(root,targetSum);
        return ans;
    }
