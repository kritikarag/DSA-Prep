// https://practice.geeksforgeeks.org/problems/largest-subtree-sum-in-a-tree/1

int ans = INT_MIN;
int tree(Node *root)
{
    if (root == NULL)
        return 0;

    auto left = tree(root->left);
    auto right = tree(root->right);
    int tot = left + right + root->data;
    ans = max(ans, tot);
    return tot;
}
int findLargestSubtreeSum(Node *root)
{
    // Write your code here
    tree(root);
    return ans;
}