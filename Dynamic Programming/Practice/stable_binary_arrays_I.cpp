// https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/

const int MOD = 1000000007;
int ans = 0, n;
vector<vector<vector<int>>>dp;
int solve(int zero, int one, int limit, bool prev){
    if(zero<0||one<0)return 0;
    if (zero == 0 && one == 0) return 1;
    
    if(dp[zero][one][prev]!=-1)return dp[zero][one][prev];
    
    int takeone = 0;
    
    if(prev){
        for(int i=1;i<=min(limit,one);i++)
        {
            takeone += solve(zero, one-i, limit,false)%MOD;
            takeone%=MOD;
        }
    }
    
    int takezero = 0;
    
    if(!prev){
        for(int i=1;i<=min(limit,zero);i++){
            takezero += solve(zero-i, one, limit, true)%MOD;
            takezero%=MOD;
        }
    }
    
    return dp[zero][one][prev] = (takezero+takeone)%MOD;
}
int numberOfStableArrays(int zero, int one, int limit) {
    n=one+zero;
    dp.resize(zero+1,vector<vector<int>>(one+1,vector<int>(2,-1)));        
    ans = (solve(zero,one,limit, true)%MOD+solve(zero,one,limit,false)%MOD)%MOD;
    return ans%MOD;
}
