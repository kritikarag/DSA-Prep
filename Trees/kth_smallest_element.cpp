// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

void solve(Node *root, int &K, int &ans)
{
    if (!root)
        return;

    solve(root->left, K, ans);
    K--;
    if (K == 0)
    {
        ans = root->data;
        return;
    }
    solve(root->right, K, ans);
}
// Return the Kth smallest element in the given BST
int KthSmallestElement(Node *root, int K)
{ 
    int ans = -1;
    solve(root, K, ans);
    return ans;
}