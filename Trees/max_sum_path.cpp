int maxSumPath(TreeNode*root,int &maxsum){
    if(!root)return 0;

    int leftsum = maxSumPath(root->left, maxsum);
    int rightsum = maxSumPath(root->right,maxsum);

    maxsum = max(maxsum, leftsum+rightsum+root->val);

    return root->val+max(leftsum,rightsum);
}

int maximumPathSum(TreeNode* root){
    int maxsum=0;
    maxSumPath(root,maxsum);
}