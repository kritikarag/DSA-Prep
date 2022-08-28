// https://practice.geeksforgeeks.org/problems/reverse-array-in-groups0255/1

void reverseInGroups(vector<long long> &arr, int n, int k)
{
    int i;
    for (i = 0; i + k <= n; i += k)
    {
        reverse(arr.begin() + i, arr.begin() + i + k);
    }
    if (i < n)
        reverse(arr.begin() + i, arr.begin() + n);
}