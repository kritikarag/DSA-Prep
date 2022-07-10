void recursion(TreeNode* root, int level, vector<int> &ans){
        
        if(root==nullptr) return;
        
        //If size==level then push it to ds
        if(ans.size()==level) ans.push_back(root->val);
        
        recursion(root->right,level+1,ans);
        recursion(root->left,level+1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
       
        vector<int> ans;
        recursion(root,0,ans);
        
        return ans;
    }
