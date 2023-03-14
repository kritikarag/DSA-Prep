// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/

int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    arr[0] = 1;
    int maxi = arr[0];
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (abs(arr[i + 1] - arr[i]) > 1)
        {
            arr[i + 1] = arr[i] + 1;
        }
        maxi = max(maxi, arr[i + 1]);
    }
    return maxi;
}

