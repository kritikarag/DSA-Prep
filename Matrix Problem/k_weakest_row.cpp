// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    int n = mat.size(), m = mat[0].size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = m - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mat[i][mid] == 1)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        pq.push({high + 1, i});
    }

    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}