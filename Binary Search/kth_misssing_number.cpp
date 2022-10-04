// https://leetcode.com/problems/kth-missing-positive-number/

int findKthPositive(vector<int> &arr, int k)
{
    for (auto a : arr)
        if (a <= k)
            k++;
    return k;
}

int findKthPositive(vector<int> &arr, int k)
{
    int l = 0, r = arr.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] - m > k)
            r = m - 1;
        else
            l = m + 1;
    }
    return k + l;
}