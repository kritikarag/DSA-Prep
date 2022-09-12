bool getPath(Node *root, vector<int> &res, int x)
{
    if (!root)
        return false;

    res.push_back(root->data);

    if (root->data == x)
        return true;

    if (getPath(root->left, res, x) || getPath(root->right, res, x))
        return true;

    res.pop_back();
    return false;
}

//Print resultant array in the main function