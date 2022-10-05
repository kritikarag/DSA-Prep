// https://leetcode.com/problems/add-one-row-to-tree/

TreeNode *addOneRow(TreeNode *root, int val, int depth)
{
    if (depth == 1)
    {
        TreeNode *node = new TreeNode(val);
        node->left = root;
        root = node;
        return root;
    }

    queue<TreeNode *> q;
    q.push(root);
    int count = 0;
    while (!q.empty())
    {
        int n = q.size();
        count++;
        while (n--)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (depth - 1 != count)
            {
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            else
            {
                TreeNode *newNode = new TreeNode(val);
                newNode->left = curr->left;
                curr->left = newNode;
                TreeNode *newNode2 = new TreeNode(val);
                newNode2->right = curr->right;
                curr->right = newNode2;
            }
        }
    }

    return root;
}