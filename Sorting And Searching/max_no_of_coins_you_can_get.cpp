// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

int maxCoins(vector<int> &piles)
{
    int n = piles.size();
    sort(piles.begin(), piles.end());
    int result = 0, chance = n / 3; 
    for (int i = chance; i < piles.size(); i += 2)
    {
        result += piles[i];
    }
    return result;
}