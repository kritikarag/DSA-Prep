// https://leetcode.com/problems/invert-binary-tree/description/

Recursive Approach:

TreeNode* invertTree(TreeNode* root) {
    if(root==NULL)return NULL;
    
    TreeNode* temp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right=temp;
    
    return root;
}

Iterative Approach:

TreeNode* invertTree(TreeNode* root) {
    if(!root)return NULL;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        auto temp = st.top();
        st.pop();
        if(temp->left)st.push(temp->left);
        if(temp->right)st.push(temp->right);
        swap(temp->left,temp->right);
    }
    return root;
}
