// https://leetcode.com/problems/delete-leaves-with-a-given-value/description/

TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if(root->left)root->left = removeLeafNodes(root->left,target);
    if(root->right)root->right = removeLeafNodes(root->right,target);

    if(root->left==nullptr && root->right==nullptr && root->val==target){
        //delete root;
        return nullptr;
    }
    return root;
}
