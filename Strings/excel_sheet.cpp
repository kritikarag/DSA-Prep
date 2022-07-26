
string convertToTitle(int cn)
{
    string res = "";
    while (cn > 0)
    {
        cn -= 1;
        res = (char)(cn % 26 + 'A') + res;
        cn /= 26;
    }
    return res;
}