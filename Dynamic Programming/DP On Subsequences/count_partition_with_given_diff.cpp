// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

int mod = 1e9+7;
vector<vector<int>>dp;
int solve(int index, vector<int>&arr, int target){
    if(target<0)return 0;
    
    if(index>=arr.size()){
        return (target==0);
    }
    
    if(dp[index][target]!=-1)return dp[index][target];
    
    int take = solve(index+1,arr,target-arr[index]);
    take%=mod;
    int not_take = solve(index+1,arr,target);
    not_take%=mod;
    
    //cout<<index<<" "<<take<<" "<<not_take<<endl;
    
    return dp[index][target] = (take+not_take)%mod;
}
int countPartitions(int n, int d, vector<int>& arr) {
    // Code here
    int sum = 0;
    for(int i:arr){
        sum+=i;
    }
    
    int total = sum+d;
    
    if(total%2)return 0;
    
    total/=2;
    
    dp.resize(n,vector<int>(total+1,-1));
    
    return solve(0,arr,total); 
    //return dp[0];
}
