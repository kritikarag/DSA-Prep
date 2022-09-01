// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

void gdnode(TreeNode *root, int &count, int maxi)
{
    if (!root)
        return;
    maxi = max(root->val, maxi);
    if (maxi == root->val)
        count++;

    gdnode(root->left, count, maxi);
    gdnode(root->right, count, maxi);
}

int goodNodes(TreeNode *root)
{
    if (!root)
        return 0;
    int count = 0, maxi = INT_MIN;

    gdnode(root, count, maxi);
    return count;
}