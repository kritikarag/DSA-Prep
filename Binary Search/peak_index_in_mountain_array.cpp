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


//Another Binary Search Approach

int peakIndexInMountainArray(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[mid + 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Iterative Search Method

int peakIndexInMountainArray(vector<int> &arr)
{
    int left = 0;
    while (arr[left] < arr[left + 1])
        left++;
    return left;
}