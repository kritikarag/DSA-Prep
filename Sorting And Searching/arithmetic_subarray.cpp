// https://leetcode.com/problems/arithmetic-subarrays/description/

vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
{
    int n = nums.size(), m = l.size();
    vector<bool> ans;
    for (int i = 0; i < m; i++)
    {
        int left = l[i], right = r[i];
        vector<int> temp = nums;
        sort(temp.begin() + left, temp.begin() + right + 1);
        int diff = temp[left + 1] - temp[left];
        bool flag = true;
        for (int j = left; j <= right; j++)
        {
            cout << temp[j] << " ";
        }
        cout << endl;
        for (int j = left; j < right; j++)
        {
            if ((temp[j + 1] - temp[j]) != diff)
            {
                // cout<<temp[j]<<" "<<temp[j+1]<<endl;
                flag = false;
                break;
            }
        }
        ans.push_back(flag);
    }
    return ans;
}