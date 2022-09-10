#include<bits/stdc++.h>
using namespace std;

int maxProfit(int ind,int buy, int cap, int n,vector<int>&prices){
    if(ind==n||cap==0)return 0;
    if(buy){
        int take = maxProfit(ind+1,1,cap,n,prices) - prices[ind];
        int not_take = maxProfit(ind+1,0,cap,n,prices);
        int profit = max(take,not_take);
    }
    else {
        int sell = maxProfit(ind+1,1,cap--,n,prices)+prices[ind];
        int not_sell = maxProfit(ind+1,0,cap,n,prices);
        int profit = max(sell,not_sell);
    }
    return profit;
}

//MEMORIZATION

int maxProfit(int ind, int buy, int cap, int n, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    if (ind == n || cap == 0)
        return 0;
    if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];

    int profit;
    if (buy)
    {
        int take = maxProfit(ind + 1, 0, cap, n, prices,dp) - prices[ind];
        int not_take = maxProfit(ind + 1, 1, cap, n, prices,dp);
        profit = max(take, not_take);
    }
    else
    {
        int sell = maxProfit(ind + 1, 1, cap-1, n, prices,dp) + prices[ind];
        int not_sell = maxProfit(ind + 1, 0, cap, n, prices,dp);
        profit = max(sell, not_sell);
    }
    return dp[ind][buy][cap]=profit;
}

int maximumProfit(vector<int> &prices, int n)
{
    // Creating a 3d - dp of size [n][2][3]
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    return maxProfit(0, 1, 2, n, prices, dp);
}

//TABULATION

int maximumProfit(vector<int>&prices,int n){
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    for(int i = n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy){
                    int take = dp[i+1][0][cap] - prices[i];
                    int not_take = dp[i+1][1][cap];
                    dp[i][buy][cap] = max(take,not_take);
                }
                else{
                    int sell = dp[i+1][1][cap-1]+prices[i];
                    int not_sell = dp[i+1][0][cap];
                    dp[i][buy][cap] = max(sell,not_sell);
                }
            }
        }
    }
    return dp[0][1][2];
}

//SPACE OPTIMIZATION

int maximumProfit(vector<int>&prices, int n){
    vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy)
                {
                    int take = ahead[0][cap] - prices[i];
                    int not_take = ahead[1][cap];
                    curr[buy][cap] = max(take, not_take);
                }
                else
                {
                    int sell = ahead[1][cap - 1] + prices[i];
                    int not_sell = ahead[0][cap];
                    curr[buy][cap] = max(sell, not_sell);
                }
            }
        }
        ahead = curr;
    }
    return ahead[1][2];
}

int main()
{

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    cout << "The maximum profit that can be generated is " << maximumProfit(prices, n);
}
