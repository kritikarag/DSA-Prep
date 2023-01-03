// https://leetcode.com/problems/bulls-and-cows/description/

string getHint(string secret, string guess)
{
    map<char, int> mp1, mp2;
    int x = 0, y = 0, n = secret.length();
    for (int i = 0; i < n; i++)
    {
        if (secret[i] == guess[i])
            x++;
        else
        {
            mp1[secret[i]]++;
            mp2[guess[i]]++;
        }
    }

    for (auto it : mp1)
    {
        if (mp2[it.first] > 0)
        {
            y += min(it.second, mp2[it.first]);
        }
    }

    string ans = to_string(x) + "A" + to_string(y) + "B";
    return ans;
}