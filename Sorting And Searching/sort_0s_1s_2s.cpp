// https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

void sortColors(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1, mid = 0;
    for (int mid = 0; mid <= high; mid++)
    {
        if (nums[i] == 0)
            swap(nums[mid], nums[low++]);
        if (nums[i] == 2)
            swap(nums[mid--], nums[high--]);
    }
}