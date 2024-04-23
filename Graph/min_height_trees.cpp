vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

    if(n==1)return {0};
    vector<int>graph[n];
    vector<int>inorder(n,0);

    for(auto &it:edges){
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
        inorder[it[0]]++;
        inorder[it[1]]++;
    }

    queue<int>q;
    for(int i=0;i<n;i++){
        if(inorder[i]==1)q.push(i);
    }
    vector<bool>vis(n,false);

    int rem = n;
    while(rem>2){
        int sz = q.size();
        rem-=sz;

        while(sz--){
            int curr = q.front();
            q.pop(); 

            for(int child:graph[curr]){
                if(--inorder[child]==1)q.push(child);
            }
        }
    }

    vector<int>ans;

    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
    }
    return ans;

}
