// https://leetcode.com/problems/partition-labels/description/

vector<int> partitionLabels(string s)
{
    int n = s.length();
    // if(s[j]==s[n-1])return{n};
    vector<int> ans, ind(26, 0);
    for (int i = 0; i < n; i++)
    {
        ind[s[i] - 'a'] = i;
    }
    int curr = -1, last = 0;
    for (int i = 0; i < n; i++)
    {
        curr = max(curr, ind[s[i] - 'a']);
        if (curr == i)
        {
            ans.push_back(curr - last + 1);
            last = curr + 1;
        }
    }
    return ans;
}