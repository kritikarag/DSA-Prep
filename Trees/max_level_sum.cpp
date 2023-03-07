// https://practice.geeksforgeeks.org/problems/4b7ff87c26ed23b3f63c25c611690213d44fb6aa/1

int maxLevelSum(Node *root)
{
    int res = INT_MIN;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        int ans = 0;
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            ans += temp->data;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        res = max(res, ans);
    }
    return res;
}