// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> kmp(string &str, string &pat)
{
    int n = str.length();
    int m = pat.length();

    vector<int> lps(m, 0);

    int i = 1, count = 0, j;
    while (i < m)
    {
        if (pat[i] == pat[count])
        {
            lps[i++] = ++count;
        }
        else
        {
            if (count != 0)
            {
                count = lps[count - 1];
            }
            else
            {
                lps[i++] = 0;
            }
        }
    }

    vector<int> indexes;
    i = 0, j = 0;

    while ((n - i) >= (m - j))
    {
        if (str[i] == pat[j])
        {
            // cout<<j<<" ";
            i++;
            j++;
        }
        else
        {
            if (j > 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == m)
        {
            indexes.push_back(i - j);
            j = lps[j - 1];
        }
    }
    return indexes;
}
vector<int> beautifulIndices(string s, string a, string b, int k)
{
    int n = s.length(), an = a.length(), bn = b.length();
    vector<int> storea = kmp(s, a);
    vector<int> storeb = kmp(s, b);
    vector<int> ans;
    // for(int i:storea)cout<<i<<" ";
    // cout<<endl;
    // for(int i:storeb)cout<<i<<" ";
    // cout<<endl;
    for (int i = 0; i < storea.size(); i++)
    {
        int index = storea[i];
        int left = max(0, index - k);
        int right = min(n - 1, index + k);

        int curr = lower_bound(storeb.begin(), storeb.end(), left) - storeb.begin();
        // cout<<left<<" "<<right<<" "<<storeb[curr]<<endl;
        if (curr == storeb.size())
            continue;

        if (storeb[curr] >= left && storeb[curr] <= right)
        {
            ans.push_back(index);
        }
    }
    return ans;
}