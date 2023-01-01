// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
vector<int> ans;
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
}
int kthSmallest(TreeNode *root, int k)
{
    inorder(root);
    return ans[k - 1];
}

// Inorder SPace Optimized
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