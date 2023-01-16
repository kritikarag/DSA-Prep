// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/

int getMaxLen(vector<int> &nums)
{
    int n = nums.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        int start = i;
        int count_neg = 0;

        while (start < n && nums[start] == 0)
            start++;

        int index = start, first_neg = -1, last_neg = -1;

        while (nums[index] != 0 && index < n)
        {

            if (nums[i] < 0)
            {
                count_neg++;
                if (first_neg == -1)
                    first_neg = index;
                last_neg = index;
            }
            index++;
        }

        // If there are even number of negartive numbers in a subarray then whole subarray will be taken for calculation
        if (count_neg % 2 == 0)
        {
            ans = max(ans, index - start);
        }

        //If there are odd numbers of negative numbers then length from first negative to last negative will be considered
        else
        {
            if (first_neg != -1)
            {
                ans = max(ans, index - first_neg - 1);
            }
        }
    }
    return ans;
}