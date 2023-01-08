// https://leetcode.com/problems/max-points-on-a-line/description/

int maxPoints(vector<vector<int>> &points)
{
    unordered_map<float, int> mp;
    int n = points.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float y2 = points[j][1], y1 = points[i][1];
            float x2 = points[j][0], x1 = points[i][0];
            float slope = (y2 - y1) / (x2 - x1);
            if ((y2 - y1) < 0 && (x2 - x1) == 0) // infinite slope
                mp[abs(slope)]++;
            else
                mp[slope]++;
        }
        for (auto it : mp)
        {
            ans = max(ans, it.second);
        }
        mp.clear();
    }

    return ans + 1;
}