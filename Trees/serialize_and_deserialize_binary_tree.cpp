// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

string serialize(TreeNode *root)
{
    if (!root)
        return "#";
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data == "#")
        return NULL;
    stringstream s(data);
    return transform(s);
}

TreeNode *transform(stringstream &s)
{
    string str;
    getline(s, str, ',');
    if (str == "#")
        return NULL;
    TreeNode *temp = new TreeNode(stoi(str));
    temp->left = transform(s);
    temp->right = transform(s);
    return temp;
}