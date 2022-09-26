// https://leetcode.com/problems/satisfiability-of-equality-equations/

vector<char> parent;
char find(char x)
{
    return parent[x] == x ? x : find(parent[x]);
}

public:

bool equationsPossible(vector<string> &equations)
{
    int n = equations.size();
    parent.resize(26, 0);
    for (int i = 0; i < 26; i++)
        parent[i] = i;
    for (int i = 0; i < n; i++)
    {
        if (equations[i][1] == '=')
        {
            int x = find(equations[i][0] - 'a');
            int y = find(equations[i][3] - 'a');
            if (x != y)
                parent[y] = x;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (equations[i][1] == '!')
        {
            int x = find(equations[i][0] - 'a');
            int y = find(equations[i][3] - 'a');
            if (x == y)
                return false;
        }
    }
    return true;
}