// https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1

bool isIsomorphic(Node *root1, Node *root2)
{
    // add code here.
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->data != root2->data)
        return false;

    bool a = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);

    bool b = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);

    return a || b;
}