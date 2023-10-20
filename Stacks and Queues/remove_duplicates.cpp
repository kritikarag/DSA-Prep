// https://leetcode.com/problems/remove-duplicate-letters/

string removeDuplicateLetters(string s)
{
    stack<char> st;
    vector<int> lastoccurence(26, 0);
    vector<bool> seen(26, false);

    for (int i = 0; i < s.length(); i++)
    {
        lastoccurence[s[i] - 'a'] = i;
    }

    for (int i = 0; i < s.length(); i++)
    {
        int curr = s[i] - 'a';

        if (seen[curr])
            continue;

        while (!st.empty() && st.top() > s[i] && i < lastoccurence[st.top() - 'a'])
        {
            seen[st.top() - 'a'] = false;
            st.pop();
        }
        st.push(s[i]);
        seen[curr] = true;
    }

    string ans = "";
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}