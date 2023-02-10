// https://practice.geeksforgeeks.org/problems/45fa306a9116332ece4cecdaedf50f140bd252d4/1

int maxInstance(string s)
{
    map<char, int> m;

    for (int i = 0; i < s.size(); i++)
        m[s[i]]++;

    return min({m['b'], m['a'], (m['l']) / 2, (m['o']) / 2, m['n']});
}