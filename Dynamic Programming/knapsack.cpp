#include<bits/stdc++.h>
using maspaace std;

int dp[100][100];

//RECURSIVE CODE
int knapsack(int arr[],int wt[],int w,int n){
    if(n==0||w==0)return 0;
    if(dp[n][w]!=-1)return dp[n][m];
    if(wt[n-1]<=w){
        return dp[n][w]= max(arr[n-1]+knapsack(arr,wt,w-wt[n-1],n-1),knapsack(arr,wt,w,n-1));
    } 
    else if(wt[n-1]>w)return dp[n][w] = knapsack(arr,wt,w,n-1);
}

//TOP-DOWN APPROACH

int knapsack(int arr[],int wt[],int w,int n){
    for (int i = 0; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for(inti=1;i<n+1;i++)
        for(int j=1;j<w+1;j++)
            if(wt[i-1]<=j){
                dp[i][j]=max(arr[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];

    return dp[n][w];
}

//SUBSET SUM PROBLEM

bool subsetsum(int arr[],int n,int sum){
    bool dp[n+1][sum+1];
    for(int j=0;j<=sum;j++){
        dp[0][j]=False;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=True;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][sum];
}

//EQUAL PARTITION
bool equalpart(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2==1)return false;
    else{
        return subsetsum(arr,n,sum/2);
    }
}

//NUMBER OF SUBSETS SUM EQUAL TO K

int numubsets(int arr[],int n,int k){
    int dp[n+1][k+1];
    for(int i=0;i<=sum;i++)dp[0][i]=0;
    for(int i=0;i<=n;i++)dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(arr[i-1]<=j)dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int minsubsetsumdiff(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
    bool dp[n+1][sum+1]
    for(int i=0;i<=sum;i++)dp[0][i]=false;
    for(int i=0;i<=n;i++)dp[i][0]=true;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j)dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
        }
    }

    int mn=INT_MAX;
    // vector<int>vec;
    // for(int i=0;i<=sum/2;i++){
    //     if(dp[n][i])vec.push_back(i);
    // }
    // for(int i=0;i<vec.size();i++){
    //     mn = min(mn,range-2*i);
    // }

    for(int i=sum/2;i>=0;i--){
        if(dp[n][i]){
            mn=sum-2*i;
            break;
        }
    }
    return mn; 
}

//COUNT THE NUMBER OF SUBSETS WITH A GIVEN DIFFERENCE

int countsubsetwithdiff(int arr[],int n,int diff){
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
    
    //set1 + set2 = sum;
    // set1 - set2 = diff
    
    int target = (sum+diff)/2;
    int dp[n+1][target+1];

    for(int i=0;i<=target;i++)dp[0][i]=0;
    for(int i=0;i<=n;i++)dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            dp[i][j]=dp[i-1][j];
            if(arr[i-1]<=j)dp[i][j]+=dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][target];
}

//TARGET SUM

int tagetsum(int arr[],int n,int target){
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];

    int req = (sum-target)/2;

    int dp[n+1][req+1];

    return dp[n][req];
}

int main(){
    int n,w;
    int dp[n+1][w+1];
    memset(dp,-1,sizeof(dp));
}