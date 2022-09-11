int depth (TreeNode *root) {
        if (root == NULL) return 0;
        return max (depth(root -> left), depth (root -> right)) + 1;
    }

bool isBalanced (TreeNode *root) {
    if (root == NULL) return true;
    
    int left=depth(root->left);
    int right=depth(root->right);
    
    return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

//2ND APPROACH 

int height(TreeNode* root){
    if(!root)return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if(lh==-1 || rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;

    return max(lh,rh)+1;
}

bool isBalanced(TreeNode* root){
    return height(root)!=-1
}
