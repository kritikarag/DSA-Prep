//RECURSION

int frogJump(int n, int energy[]){
    if(n==0)return 0;

    int step1 = frogJump(n-1,energy)+ abs(energy[i]-energy[i-1]);
    if(n>1)
        int step2 = frogJump(n-2,energy) + abs(energy[i]-energy[i-2]);

    return min(step1,step2);
}

//MEMORIZATION

int frogJump(int n, int energy[],vector<int>&dp)
{
    if (n == 0)
        return 0;
    if(dp[n]!=-1)return dp[n];
    int step1 = frogJump(n - 1,energy,dp) + abs(energy[i] - energy[i - 1]);
    if(n>1)
        int step2 = frogJump(n - 2,energy,dp) + abs(energy[i] - energy[i - 2]);

    return dp[n] = min(step1, step2);
}

//TABULATION

int frogJump(int n, int energy[])
{
    vector<int>dp(n,INT_MAX);
    dp[0]=0;

    for(int i=1;i<n;i++){
        int step1 = dp[n - 1] + abs(energy[i] - energy[i - 1]);
        step2=INT_MAX;
        if(n>1)
            int step2 = dp[n - 2] + abs(energy[i] - energy[i - 2]);

        dp[i] min(step1, step2);
    }

    return dp[n-1];
}

//SPACE OPTIMIZATION

int frogJump(int n, int energy[])
{
    int prev1=0,prev2=0;

    for(int i=1;i<n;i++){
        int step1 = prev1 + abs(energy[i] - energy[i - 1]);
        int step2 = INT_MAX;
        if (n > 1)
            step2 = prev2 + abs(energy[i] - energy[i - 2]);

        int curr = min(step1, step2);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
