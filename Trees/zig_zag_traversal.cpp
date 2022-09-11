vector<vector<int>>zigzagTraversal(TreeNode* root){
    vector<vector<int>>result;
    if(!root)return result;

    queue<TreeNode*>q;
    q.push(root);
    bool flag = true; //Left to Right in case true or else other way round
    while(!q.empty()){
        int n = q.size();

        vector<int>curr(n);
        for(int i=0;i<n;i++){
            TreeNode* node = q.front();
            q.pop();
            int index = (flag)?i:(n-1-i);
            curr[index] = node->val;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        flag = !flag;
        result.push_back(curr);
    }

    return result;
}

vector<int> zigZagTraversal(Node *root)
{
    if (root == NULL)
        return {};
    if (root->left == NULL && root->right == NULL)
        return {root->data};
    stack<Node *> s1, s2;
    vector<int> res;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            res.push_back(temp->data);
            if (temp->left)
                s2.push(temp->left);
            if (temp->right)
                s2.push(temp->right);
        }
        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            res.push_back(temp->data);
            if (temp->right)
                s1.push(temp->right);
            if (temp->left)
                s1.push(temp->left);
        }
    }
    return res;
    // Code here
}