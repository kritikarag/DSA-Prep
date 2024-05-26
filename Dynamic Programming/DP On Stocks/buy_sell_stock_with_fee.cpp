// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

vector<vector<int>>dp;
int solve(int index, bool sell, vector<int>&prices, int fee){
    if(index>=prices.size())return 0;

    if(dp[index][sell]!=-1)return dp[index][sell];

    if(sell){
        int give = prices[index]- fee + solve(index+1,1-sell,prices,fee);
        int not_give = solve(index+1,sell,prices,fee);

        dp[index][sell] = max(give,not_give);
    }
    else{
        int take = solve(index+1,1-sell,prices,fee) - prices[index];
        int not_take = solve(index+1,sell,prices,fee);

        dp[index][sell] = max(take,not_take);
    }

    return dp[index][sell];
}
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    dp.resize(n,vector<int>(2,-1));

    return solve(0,0,prices,fee);
}
