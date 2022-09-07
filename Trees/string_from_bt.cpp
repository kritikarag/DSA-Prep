// https://leetcode.com/problems/construct-string-from-binary-tree/

string tree2str(TreeNode *root)
{
    if (!root)
        return "";
    string res = to_string(root->val);
    if (root->left)
        res = res + "(" + tree2str(root->left) + ")";
    if (root->right)
    {
        if (!root->left)
            res += "()";
        res += "(" + tree2str(root->right) + ")";
    }
    return res;
}

string tree2str(TreeNode *root)
{
    if (root == NULL)
        return "";

    string output = to_string(root->val);

    if (root->left != NULL || root->right != NULL)
        output += "(" + tree2str(root->left) + ")";
    if (root->right != NULL)
        output += "(" + tree2str(root->right) + ")";

    return output;
}