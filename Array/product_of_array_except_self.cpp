//

vector<int> productExceptSelf(vector<int> &nums)
{
    int total = 1, cnt = 0;
    vector<int> res(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            cnt++;
        else
            total *= nums[i];
    }

    if (cnt == 0)
    {
        for (int i = 0; i < nums.size(); i++)
            res[i] = total / nums[i];
    }
    else if (cnt == 1)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                res[i] = total;
            else
                res[i] = 0;
        }
    }
    return res;
}

