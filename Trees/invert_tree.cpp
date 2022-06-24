TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return NULL;
        
        TreeNode* temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right=temp;
        
        return root;
    }
