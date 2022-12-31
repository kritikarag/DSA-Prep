// https://practice.geeksforgeeks.org/problems/af49b143a4ead583e943ca6176fbd7ea55b121ae/1

int minLaptops(int n, int start[], int end[])
{
    // Code here
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back({start[i], end[i]});
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    sort(vec.begin(), vec.end());

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (pq.size() == 0)
        {
            pq.push(vec[i].second);
            count++;
        }
        else if (pq.top() <= vec[i].first)
        {
            pq.push(vec[i].second);
            pq.pop();
        }
        else
        {
            count++;
            pq.push(vec[i].second);
        }
    }
    return count;
}