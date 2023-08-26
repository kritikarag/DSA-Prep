// https://leetcode.com/problems/maximum-length-of-pair-chain/description/

int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), [](const std::vector<int> &a, const std::vector<int> &b)
         { return a[1] < b[1]; });

    int curr = INT_MIN, ans = 0;
    for (auto it : pairs)
    {
        if (curr < it[0])
        {
            curr = it[1];
            ans++;
        }
    }
    return ans;
}