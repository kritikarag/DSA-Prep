// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/


//Method 1: Sorting

int reductionOperations(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size(), result = 0;

    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i] != nums[i - 1])
        {
            result += n - i;
        }
    }

    return result;
}

// Method 2: Hashing