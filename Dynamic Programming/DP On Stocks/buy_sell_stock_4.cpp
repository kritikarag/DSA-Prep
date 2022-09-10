// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/ 
#include<bits/stdc++.h>
using namespace std;

//RECURSION
int maxProfit(int ind, int buy, int cap, int n, vector<int>&prices){
    if(ind==n||cap==0) return 0;

    if(buy){
        int take = maxProfit(ind+1,0,cap,n,prices)-prices[ind];
        int not_take = maxProfit(ind+1,1,cap,n,prices);
        return max(take,not_take);
    }
    else{
        int sell = maxProfit(ind+1,1,cap-1,n,prices)+prices[ind];
        int not_sell = maxProfit(ind+1,0,cap,n,prices);
        return max(sell,not_sell);
    }
}

//MEMORIZATION

int maximumProfit(int ind, int buy, int cap , int n , vector<int>&prices, vector<vector<vector<int>>>&dp){
    if(ind==n||cap==0)return 0;
    if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];

    if (buy)
    {
        int take = maximumProfit(ind + 1, 0, cap, n, prices,dp) - prices[ind];
        int not_take = maximumProfit(ind + 1, 1, cap, n, prices,dp);
        return dp[ind][buy][cap]= max(take, not_take);
    }
    else
    {
        int sell = maximumProfit(ind + 1, 1, cap - 1, n, prices,dp) + prices[ind];
        int not_sell = maximumProfit(ind + 1, 0, cap, n, prices,dp);
        return dp[ind][buy][cap]= max(sell, not_sell);
    }
}

int maxProfit(int k,int n, vector<int>&prices){
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
    return maximumProfit(0,1,k,n,prices,dp);
}

//TABULATION

int maxProfit(int k, int n, vector<int>&prices){
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
    for(int ind = n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap =1;cap<=k;cap++){
                if (buy)
                {
                    int take = dp[ind+1][0][cap] - prices[ind];
                    int not_take = dp[ind + 1][1][cap];
                    dp[ind][buy][cap] = max(take, not_take);
                }
                else
                {
                    int sell = dp[ind + 1][1][cap-1] + prices[ind];
                    int not_sell = dp[ind + 1][0][cap];
                    dp[ind][buy][cap] = max(sell, not_sell);
                }
            }
        }
    }
    return dp[0][1][k];
}

//SPACE OPTIMIZATION

int maxProfit(int k, int n, vector<int> &prices)
{
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                if (buy)
                {
                    int take = ahead[0][cap] - prices[ind];
                    int not_take = ahead[1][cap];
                    curr[buy][cap] = max(take, not_take);
                }
                else
                {
                    int sell = ahead[1][cap - 1] + prices[ind];
                    int not_sell = ahead[0][cap];
                    curr[buy][cap] = max(sell, not_sell);
                }
            }
        }
        ahead = curr;
    }
    return ahead[1][k];
}

int main()
{

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;
    cout << "The maximum profit that can be generated is :" << maxProfit(k,n,prices);

    cout << "The maximum profit that can be generated is " << maxProfit(0,1,k,n,prices); //-> For recursion call
    return 0;
}