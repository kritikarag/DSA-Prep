// https://leetcode.com/problems/binary-tree-pruning/

TreeNode *pruneTree(TreeNode *root)
{
    // if(!root->val && !root->left->val && !root->right->val)return NULL;
    if (root->left)
        root->left = pruneTree(root->left);
    if (root->right)
        root->right = pruneTree(root->right);
    if (!root->val && !root->left && !root->right)
        return NULL;

    return root;
}

//BFS OF GRAPH

vector<int>bfsofGraph(int v,vector<int>adj[]){
    vector<int>bfs;
    vector<int>vis(v+1,0);

    for(int i=1;i<=v;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto it : adj[node])
                {
                    if (!vis[it])
                        q.push(it);
                        vis[it]=1;
                }
            }
        }
    }
    return bfs;
}

// DFS OF GRAPH
void dfstraversal(int node, vector<int>&vis, vector<int>adj[], vector<int>&dfs){
    dfs.push_back(node);
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfstraversal(it, vis,adj,bfs);
        }
    }
}
vector<int> dfsofGraph(int v, vector<int> &adj[])
{
    vector<int> dfs;
    vector<int> vis(v + 1, 0);

    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            dfstraversal(i,vis,adj,dfs);
        }
    }
    return dfs;
}

void cycleDetectionBFS(int v, vector<int>adj[]){
    
}
