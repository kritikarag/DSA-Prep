// https://practice.geeksforgeeks.org/problems/ec277982aea7239b550b28421e00acbb1ea03d2c/1

vector<int> maximumValue(Node *node)
{
    // code here
    vector<int> res;
    if (!node)
        return res;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        int n = q.size();
        int ans = INT_MIN;
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            ans = max(temp->data, ans);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        res.push_back(ans);
    }
    return res;
}