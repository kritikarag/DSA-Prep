// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

int maxProfit(vector<int> &prices)
{
    // initialization
    int coolDown = 0, sell = 0, hold = std::numeric_limits<int>::min();

    for (int stockPrice_Day_i : prices)
    {
        int prevCoolDown = coolDown, prevSell = sell, prevHold = hold;
        // Max profit of cooldown on Day i comes from either cool down of Day_i-1, or sell out of Day_i-1 and today Day_i is cooling day
        coolDown = max(prevCoolDown, prevSell);

        // Max profit of sell on Day_i comes from hold of Day_i-1 and sell on Day_i
        sell = prevHold + stockPrice_Day_i;

        // Max profit of hold on Day_i comes from either hold of Day_i-1, or cool down on Day_i-1 and buy on Day_i
        hold = max(prevHold, prevCoolDown - stockPrice_Day_i);
    }
    // The state of max profit must be either sell or cool down
    return max(sell, coolDown);
}