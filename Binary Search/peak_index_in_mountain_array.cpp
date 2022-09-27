// https://leetcode.com/problems/peak-index-in-a-mountain-array/

int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return -1;
}