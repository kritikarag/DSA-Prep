// https://leetcode.com/problems/path-sum-ii/

//1ST APPROACH - Optimized Space Complexity //DFS
void find(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &paths)
{
    if (!root)
        return;

    path.push_back(root->val);
    if (!root->right && !root->left && root->val == sum)
    {
        paths.push_back(path);
    }

    find(root->left, sum - root->val, path, paths);
    find(root->right, sum - root->val, path, paths);
    path.pop_back();
}
vector<vector<int>> pathSum(TreeNode *root, int target)
{
    vector<vector<int>> paths;
    vector<int> path;
    find(root, target, path, paths);
    return paths;
}

//2ND APPROACH -Optimized Time Complexity //BFS

vector<vector<int>> getAllPaths(TreeNode *root, int targetSum)
{
    queue<pair<TreeNode *, pair<int, vector<int>>>> q;
    vector<vector<int>> res;
    if (!root)
        return res;
    
    q.push({root, {root->val, {root->val}}});
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        TreeNode *treeNode = front.first;
        int currentSum = front.second.first;
        vector<int> currentPath = front.second.second;
        
        if (isLeaf(treeNode) and currentSum == targetSum)
        {
            res.push_back(currentPath);
        }
        if (treeNode->left)
        {
            vector<int> leftPath = currentPath;
            leftPath.push_back(treeNode->left->val); 
            q.push({treeNode->left, {currentSum + treeNode->left->val, leftPath}});
        }
        if (treeNode->right)
        {
            vector<int> rightPath = currentPath;
            rightPath.push_back(treeNode->right->val); 
            q.push({treeNode->right, {currentSum + treeNode->right->val, rightPath}});
        }
    }
    return res;
}