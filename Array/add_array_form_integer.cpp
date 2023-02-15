// https://leetcode.com/problems/add-to-array-form-of-integer/

vector<int> addToArrayForm(vector<int> &nums, int k)
{
    int carry = 0, i = nums.size() - 1;
    while (k && i >= 0)
    {
        int temp = k % 10;
        int sum = nums[i] + temp + carry;
        nums[i--] = sum % 10;
        carry = sum / 10;
        k /= 10;
    }

    while (k)
    {
        int temp = k % 10 + carry;
        nums.insert(nums.begin(), temp % 10);
        k /= 10;
        carry = temp / 10;
    }
    while (i >= 0)
    {
        int sum = nums[i] + carry;
        nums[i--] = sum % 10;
        carry = sum / 10;
    }

    if (carry)
        nums.insert(nums.begin(), 1);

    return nums;
}