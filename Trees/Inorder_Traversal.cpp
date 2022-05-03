vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vector;
        stack<TreeNode *> stack;
        TreeNode *pCurrent = root;
        
        while(!stack.empty() || pCurrent)
        {
            if(pCurrent)
            {
                stack.push(pCurrent);
                pCurrent = pCurrent->left;
            }
            else
            {
                TreeNode *pNode = stack.top();
                vector.push_back(pNode->val);
                stack.pop();
                pCurrent = pNode->right;
            }
        }
        return vector;
    }
