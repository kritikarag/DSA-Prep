// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

int minCost(string colors, vector<int> &t)
{
    int res = t[0], max_curr = t[0];
    for (int i = 1; i < colors.length(); i++)
    {
        if (colors[i] != colors[i - 1])
        {
            res -= max_curr;
            max_curr = 0;
        }
        res += t[i];
        max_curr = max(max_curr, t[i]);
    }

    return res - max_curr;
}