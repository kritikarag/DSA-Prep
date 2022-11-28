vector<int> findSubarray(int a[], int n)
{
    vector<int> ans = {-1};
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        int sum = 0;
        while (a[i] >= 0 && i < n)
        {
            sum += a[i];
            v.push_back(a[i]);
            i++;
        }
        if (sum > s)
        {
            ans = v;
            s = sum;
        }
    }
    return ans;
}