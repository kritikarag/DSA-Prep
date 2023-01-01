// https://leetcode.com/problems/delete-node-in-a-bst/description/?envType=study-plan&id=data-structure-ii

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left && !root->right)
            return NULL;
        if (!root->left || !root->right)
        {
            return root->left ? root->left : root->right;
        }
        else
        {
            TreeNode *temp = root->left;
            while (temp->right)
                temp = temp->right;
            root->val = temp->val;
            root->left = deleteNode(root->left, temp->val);
        }
    }
    return root;
}