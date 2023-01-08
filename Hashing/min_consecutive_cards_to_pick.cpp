// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/

int minimumCardPickup(vector<int> &cards)
{
    unordered_map<int, int> mp;
    int len = INT_MAX;
    for (int i = 0; i < cards.size(); i++)
    {
        if (mp.find(cards[i]) != mp.end())
        {
            len = min(len, i - mp[cards[i]] + 1);
        }
        mp[cards[i]] = i;
    }
    return len == INT_MAX ? -1 : len;
}