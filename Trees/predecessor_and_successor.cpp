// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

void predecessor(Node *node, int k, Node *&pre)
{
    if (node == NULL)
        return;
    if (node->key >= k)
        predecessor(node->left, k, pre);
    else
    {
        pre = node;
        predecessor(node->right, k, pre);
    }
}

void successor(Node *node, int k, Node *&suc)
{
    if (node == NULL)
        return;
    if (node->key > k)
    {
        suc = node;
        successor(node->left, k, suc);
    }
    else
    {
        successor(node->right, k, suc);
    }
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int k)
{
    predecessor(root, k, pre);
    successor(root, k, suc);
}