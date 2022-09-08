#include <bits/stdc++.h>
using namespace std;

//RECURSION
int maxSum(int n, vector<int> &vec, vector<int> &dp)
{
    if (n <= 0)
        return 0;

    int pick = vec[ind] + maxSum(ind - 2, vec, dp);
    int not_pick = maxSum(n - 1, vec, dp);

    return max(pick, not_pick);
}
//MEMORIZATION
vector<int>dp(n,-1);
int maxSum(int n, vector<int>&vec, vector<int>&dp){
    if(n<=0)return 0;
    if(dp[n]!=-1)return dp[n];

    int pick = vec[ind]+maxSum(ind-2,vec,dp);
    int not_pick = maxSum(n-1,vec,dp);

    return dp[n] = max(pick,not_pick);
}
//TABULATION
int maxSum(int n, vector<int>&vec){

    vector<int>dp(n);
    dp[0]=vec[0];
    dp[1]=max(dp[0],vec[1]);

    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+vec[i]);
    }

    return dp[n-1];
}

//SPACE OPTIMIZATION

int maxSum(int n, vector<int>&vec){
    int prev2 = vec[0];
    int prev1 = max(vec[1],prev2);

    for(int i=2;i<n;i++){
        int curr = max(prev1, prev2+vec[i]);

        prev2 = prev1;
        prev1=curr;
    }

    return prev1;
}

int main(){
    vector<int>vec = {2,1,4,9,11,13,12};
    int n = vec.size();
    cout<<maxSum(n,vec)<<endl;

    return 0;
}