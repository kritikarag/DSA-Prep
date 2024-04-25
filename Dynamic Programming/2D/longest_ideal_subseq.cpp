//https://leetcode.com/problems/longest-ideal-subsequence/description/

vector<vector<int>>dp;
int solve(char prev, int curr, string& s, int& k){
    if(curr>=s.length())return 0;

    if(dp[curr][prev]!=-1)return dp[curr][prev];

    int take = 0;
    if(prev=='#'||abs(prev-s[curr])<=k){
        take = 1 + solve(s[curr], curr+1,s,k);
    }
    int not_take = solve(prev, curr+1,s,k);
    return dp[curr][prev] = max(take,not_take);
}
int longestIdealString(string s, int k) {
    int n = s.length();
    dp.resize(n,vector<int>(130,-1));
    return solve('#',0,s,k);
}
