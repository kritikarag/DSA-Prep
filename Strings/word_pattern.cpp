// https://leetcode.com/problems/word-pattern/description/

bool wordPattern(string pattern, string s)
{

    stringstream str(s);
    int count = 0;
    string ch, word;
    while (str >> ch)
        count++;
    stringstream words(s);
    if (pattern.length() != count)
        return false;
    unordered_map<char, string> mp1;
    unordered_map<string, int> mp2;
    for (int i = 0; i < pattern.length(); i++)
    {
        words >> word;
        if (mp1.find(pattern[i]) == mp1.end() && mp2[word] <= 0)
        {
            mp1[pattern[i]] = word;
            mp2[word]++;
        }
        else
        {
            if (mp1[pattern[i]] != word)
                return false;
        }
    }
    return true;
}