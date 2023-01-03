vector<vector<int>> result;
void solve(vector<int> &temp, int k, int n)
{
    if (k == 0 && n == 0)
    {
        result.push_back(temp);
        return;
    }
    for (int i = temp.empty() ? 1 : temp.back() + 1; i <= 9; i++)
    {
        if (n - i < 0)
            break;
        temp.push_back(i);
        solve(temp, k - 1, n - i);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> temp;
    solve(temp, k, n);
    return result;
}