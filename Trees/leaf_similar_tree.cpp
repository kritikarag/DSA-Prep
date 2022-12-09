// https://leetcode.com/problems/leaf-similar-trees/description/

void collect(TreeNode *root, vector<int> &leaf)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        leaf.push_back({root->val});
    }

    if (root->left)
        collect(root->left, leaf);
    if (root->right)
        collect(root->right, leaf);
}
bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> leaf1, leaf2;
    collect(root1, leaf1);
    collect(root2, leaf2);

    if (leaf1.size() != leaf2.size())
        return false;

    for (int i = 0; i < leaf1.size(); i++)
    {
        if (leaf1[i] != leaf2[i])
            return false;
    }
    return true;
}