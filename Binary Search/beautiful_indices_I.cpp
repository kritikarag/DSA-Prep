// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> beautifulIndices(string s, string a, string b, int k)
{
    int n = s.length(), an = a.length(), bn = b.length();
    vector<int> store;
    vector<int> ans;
    if (an > n || bn > n)
        return ans;
    for (int i = 0; i <= n - bn; i++)
    {
        string temp = s.substr(i, bn);
        if (temp == b)
        {
            store.push_back(i);
        }
    }

    // for (int i : store)
    //      cout << i << " ";
    cout << endl;
    for (int i = 0; i <= n - an; i++)
    {
        int left = max(0, i - k);
        int right = min(i + k, n - 1);
        string temp = s.substr(i, an);
        if (temp == a)
        {

            int index = lower_bound(store.begin(), store.end(), left) - store.begin();
            if (index >= store.size())
                continue;
            if (store[index] >= left && store[index] <= right)
                ans.push_back(i);

            // cout <<i<<" "<< left << " " << right<<" "<<index << endl;
        }
    }

    return ans;
}