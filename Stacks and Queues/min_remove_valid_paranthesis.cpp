// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/?envType=study-plan&id=data-structure-ii

string minRemoveToMakeValid(string s)
{
    int close = count(s.begin(), s.end(), ')');
    string ans;
    int n = s.size();
    int curropen = 0, currclose = 0;
    for (char ch : s)
    {
        if (ch == '(')
        {
            if (curropen < close)
            {
                ans.push_back(ch);
                curropen++;
            }
        }
        else if (ch == ')')
        {
            if (curropen == currclose)
            {
                close--;
            }
            else
            {
                ans.push_back(ch);
                currclose++;
            }
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}
