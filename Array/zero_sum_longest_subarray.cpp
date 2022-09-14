// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

//METHOD-1 0.93s
int maxLen(vector<int> &arr, int n)
{
    map<int, int> mp;
    int curr = 0, len = 0;
    for (int i = 0; i < n; i++)
    {
        curr += arr[i];
        if (curr == 0)
            len = max(len, i + 1);
        if (mp.find(curr) != mp.end())
        {
            len = max(len, i - mp[curr]);
        }
        else
            mp[curr] = i;
    }

    return len;
}
