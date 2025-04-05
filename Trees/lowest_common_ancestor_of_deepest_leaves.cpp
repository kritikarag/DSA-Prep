// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

class Solution {
public:
    map<TreeNode*, TreeNode*>par;
    vector<TreeNode*>store;
    int maxi = -1;


    void dfs(TreeNode* node, int level){
        //ht[node->val] = level;

        if(maxi==level){
            store.push_back(node);
        }
        else if(maxi<level){
            store = {node};
            maxi = level;
        }

        if(node->left){
            par[node->left] = node;
            dfs(node->left, level+1);
        }
        if(node->right){
            par[node->right] = node;
            dfs(node->right, level+1);
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        //int height = getH(root,0);

        dfs(root, 0);

        set<TreeNode*>st;
        queue<TreeNode*>q;

        for(auto i:store){
            st.insert(i);
            q.push(i);
        }

        while(st.size()>1){
            int sz = q.size();

            st.clear();

            while(sz--){
                auto curr = q.front();
                q.pop();

                st.insert(par[curr]);
                q.push(par[curr]);
            }
        }

        return *st.begin();
    }
};
