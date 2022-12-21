// https://leetcode.com/problems/non-overlapping-intervals/description/

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int ans = 0;
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size() - 1; i++)
    {
        if (intervals[i][1] > intervals[i + 1][0])
        {
            intervals[i + 1][1] = min(intervals[i][1], intervals[i + 1][1]);
            ans++;
        }
    }
    return ans;
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int back = intervals[0][1];
    int count = 0;
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (ans.back()[1] > intervals[i][0])
        {
            ans.back()[1] = min(ans.back()[1], intervals[i][1]);
        }
        else
        {
            ans.push_back(intervals[i]);
        }
    }
    return intervals.size() - ans.size();
}