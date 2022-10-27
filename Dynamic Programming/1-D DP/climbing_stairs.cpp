int climbStairs(int n) {
        if(n<=2)return n;
        
        int prev1=1, prev2=2,res;
        for(int i=3;i<=n;i++){
            res=prev1+prev2;
            prev1=prev2;
            prev2=res;
        }
        return res;
}
int climbStairs(int n){
    if(n==2)return 2;
    if(n==1)return 1;

    return climbStairs(n-1)+climbStairs(n-2);
}
int climbStairs(int n){
    vector<int>dp(n+1,0);
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}
