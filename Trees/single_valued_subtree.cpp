// https://practice.geeksforgeeks.org/problems/single-valued-subtree/1

int evaluate(Node *root, int &ans)
{
    if (!root)
        return 1;
    // if(!root->left && !root->right)return 1;
    int left = evaluate(root->left, ans);
    int right = evaluate(root->right, ans);

    if (!left || !right)
        return 0;

    if (root->left && root->data != root->left->data)
        return 0;
    if (root->right && root->data != root->right->data)
        return 0;

    ans++;
    // code here
    return 1;
}
int singlevalued(Node *root)
{
    int ans = 0;
    evaluate(root, ans);

    return ans;
}