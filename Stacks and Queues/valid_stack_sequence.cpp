// https://leetcode.com/problems/validate-stack-sequences/description/

#include<bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int> &push, vector<int> &pop)
{
    stack<int> st;

    int i = 0, j = 0, n = push.size();
    while (i < n)
    {
        st.push(push[i++]);
        while (!st.empty() && st.top() == pop[j])
        {
            st.pop();
            j++;
        }
    }

    while (j < n)
    {
        if (st.top() != pop[j])
            return false;
        st.pop();
        j++;
    }

    return true;
}