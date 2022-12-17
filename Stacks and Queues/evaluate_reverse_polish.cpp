// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

bool issymbol(string c)
{
    if (c == "+" || c == "-" || c == "/" || c == "*")
        return true;
    else
        return false;
}
int evalRPN(vector<string> &tokens)
{
    stack<long long> s;
    int n = tokens.size();
    for (int i = 0; i < n; i++)
    {
        if (issymbol(tokens[i]))
        {
            long long b = s.top();
            s.pop();
            long long a = s.top();
            s.pop();
            if (tokens[i] == "+")
                s.push(a + b);
            else if (tokens[i] == "-")
                s.push(a - b);
            else if (tokens[i] == "*")
                s.push(a * b);
            else if (tokens[i] == "/")
                s.push(a / b);
        }
        else
        {
            s.push(stoi(tokens[i]));
        }
    }
    return (int)s.top();
}