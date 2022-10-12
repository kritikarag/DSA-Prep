// https://practice.geeksforgeeks.org/problems/save-your-life4601/1

string maxSum(string w, char x[], int b[], int n)
{
    // code here
    int temp = 0, ans = INT_MIN, j = 0;
    string res = "";

    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[x[i]] = b[i];
    }
    for (int i = 0; i < w.length(); i++)
    {
        if (mp.find(w[i]) != mp.end())
        {
            temp += mp[w[i]];
        }
        else
        {
            temp += (int)(w[i]);
        }

        if (ans < temp)
        {
            ans = temp;
            res = w.substr(j, i - j + 1);
        }

        if (temp < 0)
        {
            temp = 0;
            j = i + 1;
        }
    }

    return res;
}