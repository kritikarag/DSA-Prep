// https://leetcode.com/problems/number-of-boomerangs/

int numberOfBoomerangs(vector<vector<int>> &points)
{
    int res = 0, n = points.size();

    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> mp;
        for (int j = 0; j < n; j++)
        {
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];

            int dis = pow(dx, 2) + pow(dy, 2);

            res += (mp[dis]++) * 2;
        }
    }

    return res;
}