// https://leetcode.com/problems/verifying-an-alien-dictionary/description/

bool isAlienSorted(vector<string> &W, string O)
{
    unordered_map<char, int> alpha;
    for (int i = 0; i < O.size(); i++)
        alpha[O[i]] = i;
    for (int i = 1; i < W.size(); i++)
    {
        string a = W[i - 1], b = W[i];
        for (int j = 0; j < a.size(); j++)
        {
            if (j == b.size())
                return false;
            char achar = a[j], bchar = b[j];
            if (alpha[achar] < alpha[bchar])
                break;
            if (alpha[achar] > alpha[bchar])
                return false;
        }
    }
    return true;
}