// https://leetcode.com/problems/find-k-closest-elements/

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> vec;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int num : arr)
    {
        pq.push({abs(num - x), num});
    }
    for (int i = 0; i < k; i++)
    {
        vec.push_back(pq.top().second);
        pq.pop();
    }
    sort(vec.begin(), vec.end());

    return vec;
}