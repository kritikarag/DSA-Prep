Node* lowestBT(Node* root, Node *p, Node* q){
    if(root==NULL || root==p || root==q){
        return root;
    }

    Node* left = lowestBT(root->left, p, q);
    Node* right = lowestBT(root->right, p, q);

    if(!left)return right;
    else if(!right)return left;

    else return root;
}