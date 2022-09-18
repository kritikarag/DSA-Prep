struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
vector<int>topView(TreeNode* root){
    vector<int>ans;
    map<int,int>mp;

    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    mp[0] = root->val;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        TreeNode* temp = curr.first;
        int line = curr.second;
        if(mp.find(line)==mp.end())mp[line] = temp->val;

        if(temp->left)q.push({temp->left,line-1});
        if(temp->right)q.push({temp->right,line+1});
    }

    for(auto it: mp){
        ans.push_back(it.second);
    }

    return ans;
}