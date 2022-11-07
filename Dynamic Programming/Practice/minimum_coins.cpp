// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

vector<int> minPartition(int N)
{
    // code here
    vector<int> v = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> ans;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (N >= v[i])
        {
            N -= v[i];
            ans.push_back(v[i]);
        }
    }
    return ans;
}