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


// Prefix and Suffix 
vector<int> productExceptSelf(vector<int> &nums)
{
    int total = 1, cnt = 0;
    int n = nums.size();
    vector<int> res(n, 0), suff(n), pref(n);
    suff[n - 1] = 1;
    pref[0] = 1;
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = suff[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        res[i] = pref[i] * suff[i];
    }

    return res;
}

// Prefix and Suffix Optimized

vector<int> productExceptSelf(vector<int> &nums)
{
    int total = 1, cnt = 0;
    int n = nums.size();
    vector<int> res(n, 1);
    for (int i = 1; i < n; i++)
    {
        res[i] = res[i - 1] * nums[i - 1];
    }
    int suffixprod = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        res[i] *= suffixprod;
        suffixprod *= nums[i];
    }

    return res;
}

// Prefix and Suffix Further Optimized

vector<int> productExceptSelf(vector<int> &nums)
{
    int total = 1, cnt = 0;
    int n = nums.size();
    vector<int> res(n, 1);
    int suffixprod = 1, prefixprod = 1;
    for (int i = 0; i < n; i++)
    {
        res[i] *= prefixprod;
        prefixprod *= nums[i];
        res[n - i - 1] *= suffixprod;
        suffixprod *= nums[n - i - 1];
    }

    return res;
}