//Recursion

int numSubsetsWithDiff(vector<int>&nums, int ind, int target){
    if(target == 0)return 1;
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }

    int not_take = numSubsetsWithDiff(nums, ind-1, target);
    int take = 0;
    if(nums[ind]<=target) take = numSubsetsWithDiff(nums, ind-1, target-nums[ind]);

    return take + not_take;
}

//Memorization

int numSubsetsWithDiff(vector<int> &nums, int ind, int target, vector<vector<int>>&dp)
{
    if (target == 0)
        return 1;
    if (ind == 1)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }

    if(dp[ind][target]!=-1)return dp[ind][target];
    
    int not_take = numSubsetsWithDiff(nums, ind - 1, target, dp);
    int take = 0;
    if (nums[ind] <= target)
        take = numSubsetsWithDiff(nums, ind - 1, target - nums[ind-1]);

    return dp[ind][target] = take + not_take;
}

// Tabulation

int numSubsetsWithDiff(vector<int> &nums, int ind, int target)
{
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            int not_take = dp[i-1][j];
            int take = 0;
            if(nums[i-1]<=j)take = dp[i-1][j-nums[i-1]];

            dp[i][j] = take + not_take;
        }
    }

    return dp[n][target];
}

//Space Optimized

int numSubsetsWithDiff(vector<int> &nums, int ind, int target)
{
    vector<int>prev(target+1,0);
    prev[0]=1;
    for(int i=1;i<=n;i++){
        vector<int>curr(target+1,0);
        curr[0]=1;
        for(int j=1;j<=target;j++){
            int not_take = prev[j];
            int take = 0;
            if(nums[i-1]<=j)take = prev[j-nums[i-1]];

            curr [j] = take + not_take;
        }

        prev = curr;
    }

    return prev[target];
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);

    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }

    int diff;
    cin>>diff;
    /* Given, S1 - S2 = Diff
        Also, S1 + S2 = Sum;
        So, Target = (Diff + Sum)/2
    */
   if((diff+sum)%2){
    cout<<0<<endl;
   }
   else
   {
       int target = (diff + sum) / 2;

       cout << numSubsetsWithDiff(nums, n, target) << endl;
   }

   return 0;
}