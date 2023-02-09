// https://leetcode.com/problems/maximum-depth-of-binary-tree/

int height(Node*root){
    if(!root)return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    return 1+max(lh,rh);
}