// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

bool dis(vector<int> &vec, int target, int d)
{
    int low = 0, high = vec.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (abs(target - vec[mid]) <= d)
            return false;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return true;
}

int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{

    sort(arr2.begin(), arr2.end());
    int count = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        if (dis(arr2, arr1[i], d))
            count++;
    }

    return count;
}