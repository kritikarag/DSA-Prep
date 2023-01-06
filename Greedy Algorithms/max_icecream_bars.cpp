// https://leetcode.com/problems/maximum-ice-cream-bars/description/

int maxIceCream(vector<int> &costs, int coins)
{
    sort(costs.begin(), costs.end());
    int i = 0;
    while (i < costs.size())
    {
        if (costs[i] <= coins)
        {
            coins -= costs[i++];
        }
        else
            return i++;
    }

    return i;
}