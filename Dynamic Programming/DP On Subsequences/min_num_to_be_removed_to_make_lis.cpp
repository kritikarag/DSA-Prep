// https://practice.geeksforgeeks.org/problems/7d0fa4007b8eabadc404fcc9fa917aa52982aa96/1

int removeStudents(int h[], int n)
{
    // code here
    vector<int> dp;
    dp.push_back(h[0]);
    for (int i = 1; i < n; i++)
    {
        if (h[i] > dp.back())
            dp.push_back(h[i]);
        else
        {
            int ind = lower_bound(dp.begin(), dp.end(), h[i]) - dp.begin();
            dp[ind] = h[i];
        }
    }

    return n - dp.size();
}