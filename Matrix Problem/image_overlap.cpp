// https://leetcode.com/problems/image-overlap/

int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
{
    vector<pair<int, int>> a, b;
    for (int i = 0; i < img1.size(); i++)
    {
        for (int j = 0; j < img1[0].size(); j++)
        {
            if (img1[i][j] == 1)
                a.push_back({i, j});
            if (img2[i][j] == 1)
                b.push_back({i, j});
        }
    }

    int res = 0;
    map<pair<int, int>, int> mp;
    for (auto [i1, j1] : a)
    {
        for (auto [i2, j2] : b)
        {
            mp[{i1 - i2, j1 - j2}]++;
            res = max(res, mp[{i1 - i2, j1 - j2}]);
        }
    }

    return res;
}

int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
{
    vector<int> LA, LB;
    int N = img1.size();
    unordered_map<int, int> count;
    for (int i = 0; i < N * N; ++i)
        if (img1[i / N][i % N] == 1)
            LA.push_back(i / N * 100 + i % N);
    for (int i = 0; i < N * N; ++i)
        if (img2[i / N][i % N] == 1)
            LB.push_back(i / N * 100 + i % N);
    for (int i : LA)
        for (int j : LB)
            count[i - j]++;
    int res = 0;
    for (auto it : count)
        res = max(res, it.second);
    return res;
}