// https://practice.geeksforgeeks.org/problems/e0059183c88ab680b2f73f7d809fb8056fe9dc43/1

Given, we have to find (a-b)%k=0
=> a%k - b%k =0 
=> a%k = b%k

long long countPairs(int n, int arr[], int k)
{
    // code here
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i] % k) != mp.end())
        {
            ans += mp[arr[i] % k];
        }
        mp[arr[i] % k]++;
    }
    return ans;
}