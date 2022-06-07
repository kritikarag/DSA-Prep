bool dead(Node*root,int l,int h){
    if(!root)return false;
    if(root->data==h-1 && root->data==l+1)return true;
    return(dead(root->right,root->data,h)||dead(root->left,l,root->data));
}
bool isDeadEnd(Node *root)
{
    bool ans=dead(root,0,INT_MAX);
    return ans;
}
