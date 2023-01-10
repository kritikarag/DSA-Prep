// https://practice.geeksforgeeks.org/problems/d7e0ce338b11f0be36877d9c35cc8dfad6636957/1

int backtrack(Node *node)
{
    if (!node)
        return 0;

    int ret_val = node->data;
    node->data = backtrack(node->left) + backtrack(node->right);

    return node->data + ret_val;
}
void toSumTree(Node *node)
{
    backtrack(node);
    // Your code here
}