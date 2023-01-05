// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

static bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), comp);
    int end = points[0][1], count = 1;
    for (int i = 1; i < points.size(); i++)
    {
        if (end < points[i][0])
        {
            count++;
            end = points[i][1];
        }
    }
    return count;
}