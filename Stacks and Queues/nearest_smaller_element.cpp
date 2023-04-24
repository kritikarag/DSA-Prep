// https://practice.geeksforgeeks.org/problems/a520c08a8ea9b617be25c38b0fc2fe057e889253/1

#include<bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerTower(vector<int> arr)
{
    // code here
    stack<pair<int, int>> st;
    int n = arr.size();
    vector<int> ans(n), left(n), right(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first >= arr[i])
            st.pop();
        if (st.empty())
            left[i] = -1;
        else
            left[i] = st.top().second;
        st.push({arr[i], i});
    }

    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first >= arr[i])
            st.pop();
        if (st.empty())
            right[i] = -1;
        else
            right[i] = st.top().second;
        st.push({arr[i], i});
    }

    for (int i = 0; i < n; i++)
    {
        if (left[i] == -1 and right[i] == -1)
            ans[i] = -1;
        else if (left[i] == -1)
            ans[i] = right[i];
        else if (right[i] == -1)
            ans[i] = left[i];
        else
        {
            if (abs(i - left[i]) < abs(i - right[i]))
                ans[i] = left[i];
            else if (abs(i - left[i]) > abs(i - right[i]))
                ans[i] = right[i];
            else if (arr[left[i]] < arr[right[i]])
                ans[i] = left[i];
            else if (arr[left[i]] > arr[right[i]])
                ans[i] = right[i];
            else
                ans[i] = min(left[i], right[i]);
        }
    }

    return ans;
}