// https://practice.geeksforgeeks.org/problems/904237fa926d79126d42c437802b04287ea9d1c8/1

int minLength(string s, int n)
{
    // code here
    unordered_map<string, int> mp;
    mp["12"] = 1;
    mp["21"] = 1;
    mp["34"] = 1;
    mp["43"] = 1;
    mp["56"] = 1;
    mp["65"] = 1;
    mp["78"] = 1;
    mp["87"] = 1;
    mp["09"] = 1;
    mp["90"] = 1;
    stack<char> st;
    string res = "";
    for (int i = n - 1; i >= 0; i--)
    {
        st.push(s[i]);
        if (st.size() > 1)
        {
            string temp = "";
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();
            temp += a;
            temp += b;
            if (mp[temp] > 0)
                continue;
            else
            {
                st.push(b);
                st.push(a);
            }
        }
    }
    return st.size();
}