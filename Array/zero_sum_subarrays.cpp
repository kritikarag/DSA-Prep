// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

long long int findSubarray(vector<long long int> &arr, int n)
{
    // code here
    map<long long int, long long int> mp;
    long long count = 0, sum = 0;
    mp[0] = 0;
    for (long long int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            count++;
        if (mp[sum] > 0)
            count += mp[sum];
        mp[sum]++;
    }
    return count;
}