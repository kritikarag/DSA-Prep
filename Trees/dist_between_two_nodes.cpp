#include<bits/stdc++.h>
using namespace std;

Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;

    Node *left_lca = lca(root->left, n1, n2);
    Node *right_lca = lca(root->right, n1, n2);

    if (left_lca != NULL && right_lca != NULL)
        return root;
    if (left_lca != NULL)
        return left_lca;
    else
        return right_lca;
}
int height(Node *root, int n)
{
    if (!root)
        return INT_MIN;
    if (root->data == n)
        return 0;
    return max(height(root->left, n), height(root->right, n)) + 1;
}
int findDist(Node *root, int a, int b)
{
    // Your code here
    Node *common = lca(root, a, b);
    return height(common, a) + height(common, b);
}