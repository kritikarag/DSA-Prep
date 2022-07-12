int height(TreeNode* root,int &res){
        if(!root)return 0;
        int l = height(root->left,res);
        int r = height(root->right,res);
        res = max(res,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int res=0;
        height(root,res);
        return res;
    }
