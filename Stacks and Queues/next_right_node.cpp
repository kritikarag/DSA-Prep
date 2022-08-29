// https://practice.geeksforgeeks.org/problems/next-right-node/1

Node *nextRight(Node *root, int key)
{
    queue<Node *> q;
    if (!root)
        return new Node(-1);
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->data == key)
            {
                if (q.empty() || n == 0)
                    return new Node(-1);
                else
                    return q.front();
            }
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return new Node(-1);
    // code here
}