https://leetcode.com/problems/freedom-trail/description/

map<char,vector<int>>mp;
vector<vector<int>>dp;

int n,m;

int solve(int idx1, int idx2, string &ring, string &key){
    if(idx1>=n||idx2>=m){
        return 0;
    }
    if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];

    int ans = INT_MAX;
    for(int i:mp[key[idx2]]){
        int step = min(abs(idx1-i),n-abs(idx1-i));
        ans = min(ans,step+solve(i,idx2+1,ring,key));
    }

    return dp[idx1][idx2] = ans;
}
int findRotateSteps(string ring, string key) {
    n = ring.size(), m = key.size();
    dp.resize(n,vector<int>(m,-1));

    for(int i=0;i<n;i++){
        mp[ring[i]].push_back(i);
    }

    return solve(0,0,ring,key)+m;
}
