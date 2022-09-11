bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>check;
        if(root==NULL)return true;
        check.push(root->left);
        check.push(root->right);
        while(!check.empty()){
            TreeNode* node1 = check.front();
            check.pop();
            TreeNode* node2 = check.front();
            check.pop();
            
            if((!node1 && node2)||(!node2 && node1))return false;
            
            if(node1 && node2){
                if(node1->val != node2->val)return false;
                check.push(node1->left);
                check.push(node2->right);
                check.push(node2->left);
                check.push(node1->right);
            }
            
        }
    return true;
}
