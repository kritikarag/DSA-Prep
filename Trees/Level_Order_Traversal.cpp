vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        
        if(root==NULL)return {};
        queue<TreeNode*>st;
        
        st.push(root);
        while(!st.empty()){
            int n=st.size();
            vector<int>row;
            while(n--){
                
                if(st.front()->left)st.push(st.front()->left);
                if(st.front()->right)st.push(st.front()->right);
                row.push_back(st.front()->val);
                st.pop();
                 
            }
           res.emplace_back(row);
        }
        
        return res;
    }
