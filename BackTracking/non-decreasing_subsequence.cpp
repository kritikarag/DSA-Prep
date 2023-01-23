// https://leetcode.com/problems/non-decreasing-subsequences/description/

void bt(vector<int> &nums, vector<int> &seq, set<vector<int>> &res, int index)
{
    if (seq.size() >= 2)
    {
        res.insert(seq);
    }

    for (int i = index; i < nums.size(); i++)
    {
        if (seq.size() == 0 || nums[i] >= seq.back())
        {
            seq.push_back(nums[i]);
            bt(nums, seq, res, i + 1);
            seq.pop_back();
        }
    }
}

vector<vector<int>> findSubsequences(vector<int> &nums)
{
    set<vector<int>> res;
    vector<int> seq;
    bt(nums, seq, res, 0);
    return vector<vector<int>>(res.begin(), res.end());
}