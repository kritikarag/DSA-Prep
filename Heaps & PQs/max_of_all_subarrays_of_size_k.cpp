// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> ans;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i], i});
    }
    ans.push_back(pq.top().first);
    for (int i = k; i < n; i++)
    {
        pq.push({arr[i], i});
        while (i - pq.top().second >= k)
        {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
    // your code here
}