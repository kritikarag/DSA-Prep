// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

bool checkIfPangram(string sen)
{
    if (sen.length() < 26)
        return false;
    vector<int> mp(26, 0);
    for (int i = 0; i < sen.length(); i++)
    {
        mp[sen[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (mp[i] == 0)
            return false;
    }

    return true;
}

bool checkIfPangram(string sen)
{
    if (sen.length() < 26)
        return false;
    set<char> s;
    for (auto it : sen)
    {
        s.insert(it);
    }

    return s.size() == 26;
}
