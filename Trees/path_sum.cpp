//Approach 1

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

//Approach 2

	bool targetsum(TreeNode *root, int prev, int target)
	{
		if (root == NULL)
			return false;

		int curr = prev + root->val;
		if (curr == target && !root->left && !root->right)
			return true;

		return targetsum(root->left, curr, target) || targetsum(root->right, curr, target);
	}
	bool hasPathSum(TreeNode *root, int targetSum)
	{
		return targetsum(root, 0, targetSum);
	}