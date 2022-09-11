void traversal(TreeNode* root){
    
    vector<int>pre,in,pos;
    stack<pair<TreeNode*,int>>st;
    st.push({root,1});
    while(!st.empty()){
        auto node = st.top();
        if(node.second==1){
            pre.push_back(node.first->val);
            node.second++;
            st.push(node);
        }
        else if(node.second==2){
            in.push_back(node.first->val);
            node.second++;
            st.push(node);
        }
        else{
            pos.push_back(node.first->val);
        }
    }
}