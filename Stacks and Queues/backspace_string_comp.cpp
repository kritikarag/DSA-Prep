bool backspaceCompare(string s, string t)
{
    stack<char> s1, s2;
    int n = s.length(), m = t.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#')
        {
            if (!s1.empty())
                s1.pop();
        }
        else
        {
            s1.push(s[i]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (t[i] == '#')
        {
            if (!s2.empty())
                s2.pop();
        }
        else
        {
            s2.push(t[i]);
        }
    }

    if (s1.size() != s2.size())
        return false;
    while (!s1.empty() && !s2.empty())
    {
        if (s1.top() != s2.top())
            return false;
        s1.pop();
        s2.pop();
    }

    return true;
}