// https://practice.geeksforgeeks.org/problems/leftmost-and-rightmost-nodes-of-binary-tree/1

void printCorner(Node *root)
{
    vector<int> ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size();
        int n = sz;
        while (n--)
        {
            Node *curr = q.front();
            q.pop();
            if (n == sz - 1)
            {
                ans.push_back(curr->data);
            }

            if (sz != 1 && n == 0)
            {
                ans.push_back(curr->data);
            }

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
}