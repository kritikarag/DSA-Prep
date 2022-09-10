#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int start, end, profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    }
    return profit;
}

//RECURSION

int maxProfit(int ind, int buy, vector<int>&prices, int n){
    if(ind ==n)return 0;

    int profit = 0;
    if(buy){
        int take = maxProfit(ind+1,0,prices,n)-prices[ind];
        int not_take = maxProfit(ind+1,1,prices,n);
        profit = max(take,not_take);
    }
    else{
        int sell = maxProfit(ind+1,1,prices,n)+prices[ind];
        int not_sell = maxProfit(ind+1,0,prices,n);
        profit = max(sell,not_sell);
    }

    return profit;
}

//MEMORIZATION

int maxProfit(int ind, int buy, vector<int>&prices, vector<vector<int>>&dp,int n){
    if(ind==n) return 0;
    if(dp[ind]!=-1)return dp[ind];

    int profit;
    if(buy){
        int take = maxProfit(ind+1,0,prices,n,dp)-prices[ind];
        int not_take = maxProfit(ind+1,1,prices,n,dp);
        profit = max(take,not_take); 
    }
    else{
        int sell = maxProfit(ind+1,1,prices,dp,n)+prices[ind];
        int not_sell = maxProfit(ind+1,0,prices,dp,n);
        dp[ind][buy]=max(sell,not_sell);
    }
    dp[ind][buy] = profit;
}

// //TABULATION

int maxProfit(int n, vector<int>&prices){
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    dp[n][0]=dp[n][1]=0;

    for(int i = n-1;i>=0;i--){
        for(int buy =0;buy<=1;buy++){
            int profit;
            if (buy)
            {
                int take =  dp[i+1][0] - prices[i];
                int not_take = dp[i+1][1];
                profit = max(take, not_take);
            }
            else
            {
                int sell = dp[i+1][1] + prices[i];
                int not_sell = dp[i+1][0];
                profit = max(sell, not_sell);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

//SPACE OPTIMIZATION

int maxProfit(int n, vector<int> &prices)
{
    vector<int>ahead(2,0);
    vector<int>curr(2,0);

    ahead[0] = ahead[1] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit;
            if (buy)
            {
                int take = ahead[0] - prices[i];
                int not_take = ahead[1];
                profit = max(take, not_take);
            }
            else
            {
                int sell = ahead[1] + prices[i];
                int not_sell = ahead[0];
                profit = max(sell, not_sell);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return curr[1];
}

int main()
{

    int n = 6;
    vector<int>prices = {7, 1, 5, 3, 6, 4};
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    cout << "The maximum profit that can be generated is " << maxProfit(0,1,prices, n);//RECURSION
    cout << "The maximum profit that can be generated is " << maxProfit(0, 1, prices, dp, n);//MEMORIZATION
    cout << "The maximum profit that can be generated is " << maxProfit(n,prices);
}